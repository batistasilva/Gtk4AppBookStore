#include "mysql_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***
 * Prints the last MySQL error to stderr,
 * closes the MySQL connection, and exits the
 * program with failure status.
 *
 * Param:
 *   conn - Pointer to a valid MYSQL connection.
 *   Must not be NULL.
 *
 * This function should be called immediately
 * after a failed MySQL operation.
 **/
// Function to handle database errors
void printConnError(MYSQL *conn,
                    const char *message)
{
  fprintf(stderr, "%s: %s\n", message, mysql_error(conn));
}

void printStmtError(MYSQL_STMT *stmt,
                    const char *message)
{
  fprintf(stderr, "%s: %s\n", message, mysql_stmt_error(stmt));
  runCloseStmt(stmt);
}

/**
 * Initializes a new MySQL connection handle.
 *
 * Returns:
 *   A pointer to a new MYSQL object.
 *   Exits the program with an error if
 *   initialization fails.
 */
MYSQL *runInitMySQL(void)
{
  MYSQL *conn = mysql_init(NULL);
  //
  if (conn == NULL) {
    fputs("Error: mysql_init() failed\n", stderr);
    exit(EXIT_FAILURE); // Or call a centralized handler if available
  }
  return conn;
}

/**
 * Loads MySQL options from a config file and connects to the database.
 *
 * Parameters:
 *   conn - A pointer to an initialized MYSQL structure.
 *
 * Returns:
 *   A pointer to a connected MYSQL object on success.
 *   NULL on failure.
 */
MYSQL *loadCnf(MYSQL *conn) {

  if (conn == NULL) {
    fputs("Error: NULL MySQL connection passed to LoadMyCNF()\n", stderr);
    return NULL;
  }

  const char *cnf_path = getenv("MYSQL_CNF_PATH");
  if (cnf_path == NULL) {
    fprintf(stderr, "MYSQL_CNF_PATH not set, using default: %s\n",
            DEFAULT_MYSQL_CNF_PATH);
    cnf_path = DEFAULT_MYSQL_CNF_PATH;
  }

  if (mysql_options(conn, MYSQL_READ_DEFAULT_FILE, cnf_path) != 0) {
    fprintf(stderr, "mysql_options() failed: %s\n", mysql_error(conn));
    mysql_close(conn);
    return NULL;
  }

  if (!mysql_real_connect(conn, NULL, NULL, NULL, NULL, 0, NULL,
                          CLIENT_FOUND_ROWS)) {
    fprintf(stderr, "MySQL connection failed: %s\n", mysql_error(conn));
    mysql_close(conn);
    return NULL;
  }

  return conn;
}

/**
 * Executes a SELECT query to fetch book data from the database.
 *
 * Parameters:
 *   conn - A valid, connected MYSQL* instance. Must not be NULL.
 *   m_url - A valid, query string. Must not be NULL.
 *
 * Returns:
 *   A MYSQL_RES* result set containing the query output.
 *
 * Errors:
 *   If the query fails or the result set cannot be retrieved,
 *   this function will call finish_with_error(), which logs the error,
 *   closes the connection, and exits the program.
 *
 * Notes:
 *   - The returned MYSQL_RES* must be freed later with mysql_free_result().
 *   - Assumes the table 'book_store' exists with columns: title, author, genre.
 */
MYSQL_RES *runQuery(MYSQL *conn,
                    const char *m_url)
{

  if (mysql_query(conn, m_url)) {
    printConnError(conn, "Error MariaDB");
    runCloseConn(conn);
  }

  MYSQL_RES *result = mysql_store_result(conn);
  if (result == NULL) {
    printConnError(conn, "Error MariaDB");
  }

  return result;
}

/**
 * @brief Retrieves the next row from a MySQL result set.
 *
 * @param result A pointer to a valid MYSQL_RES structure.
 *               Must not be NULL and must contain at least one row.
 *
 * @return
 *   A MYSQL_ROW representing the next row in the result set, or
 *   NULL if there are no more rows or if an error occurs.
 *
 * Usage:
 *   Call this function in a loop to iterate through all result rows.
 *   Each row is an array of strings (char*), with NULL fields represented as
 * NULL.
 *
 * Note:
 *   The returned MYSQL_ROW pointer is invalidated by the next call to
 *   mysql_fetch_row() or by calling mysql_free_result().
 */
MYSQL_ROW getRowData(MYSQL *conn,
                     MYSQL_RES *result)
{
  MYSQL_ROW row;

  if (result == NULL) {
    printConnError(conn, "Error MYSQL_RES is NULL");
    runCloseConn(conn);
  }
  //
  row = mysql_fetch_row(result);
  //
  return row;
}

/**
 * @brief Returns the value of a field in a row, or a safe "NULL" string.
 *
 * @param row   A valid MYSQL_ROW structure from mysql_fetch_row().
 * @param index The column index (0-based).
 *
 * @return
 *   A pointer to the string value at the specified index, or
 *   the string "NULL" if the value is NULL.
 *
 * Note:
 *   This function does not check for index out-of-bounds.
 *   It assumes that the index is within the range returned by
 * mysql_num_fields().
 */
const char *getFieldValue(MYSQL_ROW row,
                          unsigned int index)
{
  if (!row)
    return "NULL";
  return row[index] ? row[index] : "NULL";
}

const char *getFieldValueSafe(MYSQL_ROW row,
                              unsigned int index,
                              unsigned int fieldCount)
{
  if (!row || index >= fieldCount)
    return "NULL";
  return row[index] ? row[index] : "NULL";
}

/**
 * @brief Returns the number of columns (fields) in the given MySQL result set.
 *
 * @param result A valid pointer to a MYSQL_RES structure.
 *
 * @return
 *   The number of fields (columns) in the result set, or
 *   -1 if the result pointer is NULL.
 *
 * Usage:
 *   Use this function to determine how many columns are present in each row
 *   of the result, especially before accessing fields by index.
 *
 * Example:
 *   int num_fields = getNumFields(result);
 *   for (unsigned int i = 0; i < num_fields; ++i) {
 *       printf("%s\n", getFieldValue(row, i));
 *   }
 */
int getNumFields(MYSQL_RES *result) {
  if (!result)
    return -1;
  return (int)mysql_num_fields(result);
}

/**
 * @brief Prints the names of all columns (fields) in the result set.
 *
 * @param result A valid pointer to a MYSQL_RES structure. Must not be NULL.
 *
 * This function fetches and prints each field (column) name separated by tabs.
 * Useful as a header row when displaying query results.
 *
 * Example output:
 *   title    author    genre
 */
void printFieldNames(MYSQL_RES *result) {
  if (!result)
    return;

  unsigned int num_fields = mysql_num_fields(result);
  MYSQL_FIELD *fields = mysql_fetch_fields(result);

  for (unsigned int i = 0; i < num_fields; ++i) {
    printf("%s\t", fields[i].name);
  }
  printf("\n");
}

/**
 * @brief runStmtInit
 * @param stmt
 * @param conn
 * @return m_stmt
 */
MYSQL_STMT *runStmtInit(MYSQL_STMT *stmt,
                        MYSQL *conn)
{

  if (conn == NULL) {
    printConnError(conn, "mysql_conn_error() failed");
  }

  stmt = mysql_stmt_init(conn);
  //
  if (stmt == NULL) {
    printStmtError(stmt, "mysql_stmt_init() failed");
    runCloseConn(conn);
  }
  //
  return stmt;
}

/**
 * @brief runStmtPrep
 * @param conn
 * @param stmt
 * @param sql_insert
 * @return 1 or 0
 */
int runStmtPrep(MYSQL *conn,
                MYSQL_STMT *stmt,
                const char *sql_insert)
{
  printf("\nInside runStmtPrep \n");
  printf("\nSql Insert: %s ", sql_insert);

  //
  int result = mysql_stmt_prepare(stmt, sql_insert, strlen(sql_insert));

  printf("\nResult Prepare: %d ", result);

  // if result = 0, everything going well
  if (result) {
    printStmtError(stmt, "mysql_stmt_prepare() failed");

    runCloseStmt(stmt);
    runCloseConn(conn);
  }
  return result;
}


/**
 * @brief runStmtBind
 * @param conn
 * @param stmt
 * @param m_content
 * @param content_size
 * @return
 */
int runStmtBind(MYSQL *conn,
                MYSQL_STMT *stmt,
                struct Content *content,
                int content_size)
{

  MYSQL_BIND bind[content_size]; // Array to hold bind parameters

  secure_memset(bind, 0, sizeof(MYSQL_BIND));

  for (int i = 0; i < content_size; i++) {

    if (strcmp(content[i].type, "string") == 0) {
      printf("\n\nContent [String] Value: %s\n: ", content->value);

      // Bind for 'name' (string)
      bind[i].buffer_type = MYSQL_TYPE_STRING;
      bind[i].buffer = (char *)content[i].value;
      bind[i].buffer_length = strlen(content[i].value);
      bind[i].is_null = 0;
      bind[i].length = NULL; // Not used for input strings
    }

    if (strcmp(content[i].type, "int") == 0) {
      printf("\n\nContent of [Int] Value %d\n: ", content[i].value_int);

      bind[i].buffer_type = MYSQL_TYPE_LONG;
      bind[i].buffer = (char *)&content[i].value_int;
      bind[i].is_null = 0;
      bind[i].length = NULL; // Not needed for fixed-size types like int
    }
  }

  if (mysql_stmt_bind_param(stmt, bind)) {
    printStmtError(stmt, "mysql_stmt_bind_param() failed");
    runCloseStmt(stmt);
    runCloseConn(conn);
  }

  printf("Parameters bound successfully.\n");

  return EXIT_SUCCESS;
}

/**
 * @brief runSQLExec
 * @param conn
 * @param stmt
 * @param m_content
 * @return
 */
int runSQLExec(MYSQL *conn,
               MYSQL_STMT *stmt,
               struct Content *content)
{
  // --- 5. Execute the Prepared Statement ---
  if (mysql_stmt_execute(stmt)) {
    // Handle unique constraint violation for email
    if (mysql_stmt_errno(stmt) ==
        1062) { // Error code 1062 is for duplicate entry
      fprintf(stderr, "Error: Content '%s' already exists.\n",
              content[0].value);
    } else {
      printStmtError(stmt, "mysql_stmt_execute() failed");
    }

    runCloseStmt(stmt);
    runCloseConn(conn);

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

/**
 * @brief runCheckAffectedRows
 * @param conn
 * @param stmt
 * @param m_content
 */
void runCheckAffectedRows(MYSQL *conn,
                          MYSQL_STMT *stmt,
                          struct Content *content)
{

  // --- 6. Check Affected Rows ---
  long long affected_rows = mysql_stmt_affected_rows(stmt);
  //
  if (affected_rows == 1) {
    printf("User '%s' inserted successfully!\n", content[0].value);
    printf("New user ID: %lld\n",
           (long long)mysql_stmt_insert_id(stmt)); // Get auto-increment ID
  } else {
    fprintf(stderr, "Error: No rows affected or more than one row affected.\n");
  }

  // --- 7. Clean Up ---
  runCloseStmt(stmt); // Close the statement
  runCloseConn(conn); // Close the database connection
  printf("Connection closed.\n");
}
