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
void trateMySQLError(MYSQL *conn, MYSQL_STMT *stmt) {
  ERROR_LOG("\n\nMySQL Error for conn: %s Stderr: %p\n", mysql_error(conn),
            stderr);
  ERROR_LOG("\n\nMySQL Error for stmt: %s Stderr: %p\n", mysql_stmt_error(stmt),
            stderr);
}

// Function to print MySQL errors
void print_mysql_error(MYSQL *conn, const char *message) {
  fprintf(stderr, "%s: %s (Error Code: %d)\n", message, mysql_error(conn),
          mysql_errno(conn));
}

/**
 * Initializes a new MySQL connection handle.
 *
 * Returns:
 *   A pointer to a new MYSQL object.
 *   Exits the program with an error if
 *   initialization fails.
 */
MYSQL *runInitMySQL(void) {
  MYSQL *conn = mysql_init(NULL);
  //
  if (conn == NULL) {
    ERROR_LOG("Error: mysql_init() failed %p\n", stderr);
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
    // fputs("Error: NULL MySQL connection passed to LoadMyCNF()\n", stderr);
    ERROR_LOG("Error: NULL MySQL connection passed to LoadMyCNF()\n: %p",
              stderr);
    return NULL;
  }

  const char *cnf_path = getenv("MYSQL_CNF_PATH");
  if (cnf_path == NULL) {
    ERROR_LOG("MYSQL_CNF_PATH not set, using default: %s%p\n",
              DEFAULT_MYSQL_CNF_PATH, stderr);
    cnf_path = DEFAULT_MYSQL_CNF_PATH;
  }

  if (mysql_options(conn, MYSQL_READ_DEFAULT_FILE, cnf_path) != 0) {
    ERROR_LOG("Error: mysql_options() failed: %p %s\n", stderr,
              mysql_error(conn));
    mysql_close(conn);
    return NULL;
  }

  if (!mysql_real_connect(conn, NULL, NULL, NULL, NULL, 0, NULL,
                          CLIENT_FOUND_ROWS)) {
    ERROR_LOG("MySQL connection failed: %p - %s\n", stderr, mysql_error(conn));
    print_mysql_error(conn, "Failed to initialize statement");

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
MYSQL_RES *runQuery(MYSQL *conn, const char *m_url) {

  if (mysql_query(conn, m_url)) {
    trateMySQLError(conn, NULL);
    print_mysql_error(conn, "Failed to initialize statement");

    runCloseConn(conn);
  }

  MYSQL_RES *result = mysql_store_result(conn);
  if (result == NULL) {
    trateMySQLError(conn, NULL);
    print_mysql_error(conn, "Failed to initialize statement");
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
MYSQL_ROW getRowData(MYSQL *conn, MYSQL_RES *result) {
  MYSQL_ROW row;

  if (result == NULL) {
    trateMySQLError(conn, NULL);
    print_mysql_error(conn, "Failed to initialize statement");

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
const char *getFieldValue(MYSQL_ROW row, unsigned int index) {
  if (!row)
    return "NULL";
  return row[index] ? row[index] : "NULL";
}

const char *getFieldValueSafe(MYSQL_ROW row, unsigned int index,
                              unsigned int fieldCount) {
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
MYSQL_STMT *runStmtInit(MYSQL_STMT *stmt, MYSQL *conn) {

  if (conn == NULL) {
    trateMySQLError(conn, NULL);
  }

  stmt = mysql_stmt_init(conn);
  //
  if (stmt == NULL) {
    trateMySQLError(NULL, stmt);
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
int runStmtPrep(MYSQL *conn, MYSQL_STMT *stmt, const char *sql_query) {

  printf("\nSql Query: %s ", sql_query);

  //
  int result = mysql_stmt_prepare(stmt, sql_query, strlen(sql_query));

  // if result = 0, everything going well
  if (result) {
    trateMySQLError(NULL, stmt);

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
int runStmtBindToArrayOfContent(MYSQL *conn, MYSQL_STMT *stmt, Content *content,
                                int content_size) {
  ShowMessage("Inside runStmtBindToArrayOfContent()", 1, 2);

  MYSQL_BIND bind[content_size]; // Array to hold bind parameters

  secure_memset(bind, 0, sizeof(MYSQL_BIND));

  for (int i = 0; i < content_size; i++) {

    if (strcmp((const char *)content[i].type, "string") == 0) {
      // ShowMessage("Inside type [String] ", 1, 2);
      // ShowMessage(content[i].m_oper.field_name, 1, 2);

      // Bind for 'name' (string)
      bind[i].buffer_type = MYSQL_TYPE_STRING;
      bind[i].buffer = (char *)content[i].m_oper.field_name;
      bind[i].buffer_length = strlen(content[i].m_oper.field_name);
      bind[i].is_null = 0;
      bind[i].length = NULL; // Not used for input strings
    }

    if (strcmp((const char *)content[i].type, "int") == 0) {
      // //Set book_id to return
      // int book_id = content[i].m_oper.field_id;

      // if(book_id > 0)
      // snprintf(content[i].m_oper.sql_res_id,
      //         sizeof(content[i].m_oper.sql_res_id), "%d",
      //         book_id);
      // ShowMessage("Inside type [Int] ", 1, 2);
      // ShowMessage(content[i].m_oper.sql_res_id, 1, 2);

      bind[i].buffer_type = MYSQL_TYPE_LONG;
      bind[i].buffer = (char *)&content[i].m_oper.field_id;
      bind[i].is_null = 0;
      bind[i].length = NULL; // Not needed for fixed-size types like int
    }
  }

  if (mysql_stmt_bind_param(stmt, bind)) {
    trateMySQLError(NULL, stmt);
    print_mysql_error(conn, "Failed to initialize statement");

    runCloseStmt(stmt);
    runCloseConn(conn);
  }

  printf("Parameters bound successfully.\n");

  return EXIT_SUCCESS;
}

/**
 * @brief runStmtBindToContent
 * @param conn
 * @param stmt
 * @param content
 * @param content_size
 * @return
 */
int runStmtBindToContent(MYSQL *conn, MYSQL_STMT *stmt, Content content) {

  printf("\n\nInside Action runStmtBindToContent().\n");

  MYSQL_BIND bind[1]; // Array to hold bind parameters

  secure_memset(bind, 0, sizeof(MYSQL_BIND));

  if (strcmp((const char *)content.type, "string") == 0) {
    printf("\n\nBind for [String].\n");

    // Bind for 'name' (string)
    bind[0].buffer_type = MYSQL_TYPE_STRING;
    bind[0].buffer = (char *)content.m_oper.field_name;
    bind[0].buffer_length = strlen(content.m_oper.field_name);
    bind[0].is_null = 0;
    bind[0].length = NULL; // Not used for input strings
  }

  if (strcmp((const char *)content.type, "int") == 0) {
    printf("\n\nBind for [Int].\n");

    bind[0].buffer_type = MYSQL_TYPE_LONG;
    bind[0].buffer = (char *)&content.m_oper.field_id;
    bind[0].is_null = 0;
    bind[0].length = NULL; // Not needed for fixed-size types like int
  }

  if (mysql_stmt_bind_param(stmt, bind)) {
    trateMySQLError(NULL, stmt);
    print_mysql_error(conn, "Failed to initialize statement");

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
int runSQLExec(MYSQL *conn, MYSQL_STMT *stmt, Content content) {
  printf("\n\nInside Action runSQLExec().\n");

  // --- 5. Execute the Prepared Statement ---
  if (mysql_stmt_execute(stmt)) {
    printf("\nSame Erro to runSQLExec().\n");
    print_mysql_error(conn, "Failed to initialize statement");

    // Handle unique constraint violation for email
    if (mysql_stmt_errno(stmt) ==
        1062) { // Error code 1062 is for duplicate entry
      //
      ERROR_LOG("MYSQL Error Code:1062 %s For CodeID: %d\n",
                mysql_stmt_error(stmt), content.m_oper.field_id);
      //
      mWriteToFile("book-store", content.m_oper.field_name);
      mWriteToFile("book-store", mysql_stmt_error(stmt));

    } else {
      mWriteToFile("book-store", content.m_oper.field_name);
      mWriteToFile("book-store", mysql_stmt_error(stmt));
      ERROR_LOG("MYSQL Error: %s ", mysql_stmt_error(stmt));
      trateMySQLError(NULL, stmt);
      print_mysql_error(conn, "Failed to initialize statement");
    }

    runCloseStmt(stmt);
    runCloseConn(conn);
    ERROR_LOG("MYSQL Error: %s ", mysql_stmt_error(stmt));

    printf("\n\nFinish Action runSQLExec().\n %s", mysql_error(conn));

    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

/**
 * @brief runCheckAffectedRows
 * @param conn
 * @param stmt
 * @param m_content
 * @return  struct Content * with result
 * of operation of insert, update or delete
 **/
Content runCheckAffectedRows(MYSQL *conn, MYSQL_STMT *stmt, Content content) {

  long long affected_rows = mysql_stmt_affected_rows(stmt);
  const char *content_data; // confirmatio data to return
  int content_id;           // confirmatio data to return

  //
  Content content_rs;
  //
  printf("\n\nInside the Action runCheckAffectedRows().\n Option: %d ",
         content.oper_type);

  switch (content.oper_type) {
    //
  case OP_INSERT:
    //
    printf("\n\nInside Oper INSERT.\n");

    if (affected_rows == 1) {
      // Get id to return
      content_id = (long long)mysql_stmt_insert_id(stmt);
      const char msg[25] = "Inserted Successfully!";
      //
      snprintf(content_rs.m_oper.sql_res_id,
               sizeof(content_rs.m_oper.sql_res_id), "%d", content_id);
      safe_strcpy(content_rs.m_oper.field_name, content.m_oper.field_name,
                  sizeof(content.m_oper.field_name));

      create_result_msg(content_rs.m_oper.sql_res_msg,
                        sizeof(content_rs.m_oper.sql_res_msg), (char *)msg,
                        content_rs.m_oper.sql_res_id,
                        content_rs.m_oper.field_name);
      //
      content_rs.oper_type = OP_INSERT;
      //
      content_rs.m_oper.status = (bool *)true;
      //
    } else {
      //
      const char msg[25] = "Insertion Error!";
      //
      //
      snprintf(content_rs.m_oper.sql_res_id,
               sizeof(content_rs.m_oper.sql_res_id), "%d",
               content.m_oper.field_id);
      safe_strcpy(content_rs.m_oper.field_name, content.m_oper.field_name,
                  sizeof(content.m_oper.field_name));

      create_result_msg(content_rs.m_oper.sql_res_msg,
                        sizeof(content_rs.m_oper.sql_res_msg), (char *)msg,
                        content_rs.m_oper.sql_res_id,
                        content_rs.m_oper.field_name);
      //
      content_rs.oper_type = OP_INSERT;
      //
      content_rs.m_oper.status = (bool *)false;
      //
      //
    }
    break;
  case OP_UPDATE:
    printf("\n\nInside Oper UPDATE.\n");

    if (affected_rows == (my_ulonglong)-1) { // Check for error condition
      print_mysql_error(conn, "Failed to get affected rows");
      const char msg[30] = "Failed to get affected rows!";

      // Set book_id to return
      int book_id = content.m_oper.field_id;

      if (book_id > 0)
        snprintf(content_rs.m_oper.sql_res_id,
                 sizeof(content_rs.m_oper.sql_res_id), "%d", book_id);
      //
      const char *field_name = content.m_oper.field_name;
      if (field_name != NULL)
        snprintf(content_rs.m_oper.field_name,
                 sizeof(content_rs.m_oper.field_name), "%s", field_name);

      create_result_msg(content_rs.m_oper.sql_res_msg,
                        sizeof(content_rs.m_oper.sql_res_msg), (char *)msg,
                        content_rs.m_oper.sql_res_id,
                        content_rs.m_oper.field_name);
      //
      content_rs.m_oper.status = (bool *)false;
      //
    } else if (affected_rows == 0) {
      const char msg[55] = "UPDATE successful, but 0 rows affected for user ID";

      // Set book_id to return
      int book_id = content.m_oper.field_id;

      if (book_id > 0)
        snprintf(content_rs.m_oper.sql_res_id,
                 sizeof(content_rs.m_oper.sql_res_id), "%d", book_id);
      //
      const char *field_name = content.m_oper.field_name;
      if (field_name != NULL)
        snprintf(content_rs.m_oper.field_name,
                 sizeof(content_rs.m_oper.field_name), "%s", field_name);

      create_result_msg(content_rs.m_oper.sql_res_msg,
                        sizeof(content_rs.m_oper.sql_res_msg), (char *)msg,
                        content_rs.m_oper.sql_res_id,
                        content_rs.m_oper.field_name);
      //
      content_rs.m_oper.status = (bool *)true;
      //
      printf("UPDATE successful, but 0 rows affected for user ID %d. (Maybe ID "
             "not found or email already same)\n",
             content.m_oper.field_id);
      // status = 0; // Consider 0 affected rows as a successful operation, but
      // note it.
    } else {
      const char msg[25] = "Updated Successfully!";

      // Set book_id to return
      int book_id = content.m_oper.field_id;

      if (book_id > 0)
        snprintf(content_rs.m_oper.sql_res_id,
                 sizeof(content_rs.m_oper.sql_res_id), "%d", book_id);
      //
      const char *field_name = content.m_oper.field_name;
      if (field_name != NULL)
        snprintf(content_rs.m_oper.field_name,
                 sizeof(content_rs.m_oper.field_name), "%s", field_name);

      create_result_msg(content_rs.m_oper.sql_res_msg,
                        sizeof(content_rs.m_oper.sql_res_msg), (char *)msg,
                        content_rs.m_oper.sql_res_id,
                        content_rs.m_oper.field_name);
      //
      content_rs.m_oper.status = (bool *)true;
      //
      printf("UPDATE successful: %llu row(s) affected for user ID %d.\n",
             affected_rows, book_id);
      //  status = 0; // Success
    }
    break;
  case OP_DELETE:
    printf("\n\nInside Oper DELETE.\n");

    if (affected_rows > 0) {
      const char msg[25] = "Deleted successfully!";

      // Set book_id to return
      snprintf(content_rs.m_oper.sql_res_id,
               sizeof(content_rs.m_oper.sql_res_id), "%d",
               content.m_oper.field_id);

      // Set author to return
      snprintf(content_rs.m_oper.field_name,
               sizeof(content_rs.m_oper.field_name),"%s",
               content.m_oper.field_name);

      create_result_msg(
          content_rs.m_oper.sql_res_msg,         // To receipt data
          sizeof(content_rs.m_oper.sql_res_msg), // Size to set data
          (char *)msg,                           // Message to return
          content_rs.m_oper.sql_res_id,          // book_id to return
          content_rs.m_oper.field_name);         // author to return
      //
      content_rs.oper_type = OP_DELETE;
      //
      content_rs.m_oper.status = (bool *)true;
      //
    } else if (affected_rows == 0) {
      const char *msg = "Deleted Error!";
      //
      // Set book_id to return
      snprintf(content_rs.m_oper.sql_res_id,
               sizeof(content_rs.m_oper.sql_res_id), "%d",
               content.m_oper.field_id);

      // Set author to return
      snprintf(content_rs.m_oper.field_name,
               sizeof(content_rs.m_oper.field_name), "%s",
               content.m_oper.field_name);

      create_result_msg(
          content_rs.m_oper.sql_res_msg,         // To receipt data
          sizeof(content_rs.m_oper.sql_res_msg), // Size to set data
          (char *)msg,                           // Message to return
          content_rs.m_oper.sql_res_id,          // book_id to return
          content_rs.m_oper.field_name);         // author to return
      //
      content_rs.oper_type = OP_DELETE;
      //
      content_rs.m_oper.status = (bool *)false;
      //
    } else {
      const char msg[25] = "Deleted Error 2.";
      //
      // Set book_id to return
      snprintf(content_rs.m_oper.sql_res_id,
               sizeof(content_rs.m_oper.sql_res_id), "%d",
               content.m_oper.field_id);

      // Set author to return
      snprintf(content_rs.m_oper.field_name,
               sizeof(content_rs.m_oper.field_name),"%s" ,
               content.m_oper.field_name);

      create_result_msg(
          content_rs.m_oper.sql_res_msg,         // To receipt data
          sizeof(content_rs.m_oper.sql_res_msg), // Size to set data
          (char *)msg,                           // Message to return
          content_rs.m_oper.sql_res_id,          // book_id to return
          content_rs.m_oper.field_name);         // author to return
      //
      content_rs.oper_type = OP_DELETE;
      //
      content_rs.m_oper.status = (bool *)false;
      //
      trateMySQLError(NULL, stmt);
    }
    break;
  default:
    const char msg[25] = "No Option found.";
    //
    // Set book_id to return
    snprintf(content_rs.m_oper.sql_res_id, sizeof(content_rs.m_oper.sql_res_id),
             "%d", content.m_oper.field_id);

    // Set author to return
    snprintf(content_rs.m_oper.field_name,
             sizeof(content_rs.m_oper.field_name),"%s",
             content.m_oper.field_name);

    create_result_msg(content_rs.m_oper.sql_res_msg,         // To receipt data
                      sizeof(content_rs.m_oper.sql_res_msg), // Size to set data
                      (char *)msg,                   // Message to return
                      content_rs.m_oper.sql_res_id,  // book_id to return
                      content_rs.m_oper.field_name); // author to return
    //
    content_rs.oper_type = OP_UNKNOWN;
    //
    content_rs.m_oper.status = (bool *)false;
    //
    return content_rs; // Indicate failure
  }

  // --- 7. Clean Up ---
  runCloseStmt(stmt); // Close the statement
  runCloseConn(conn); // Close the database connection
  printf("Connection closed.\n");
  //
  printf("\n\nFinish runCheckAffectedRows().\n");

  return content_rs;
}

/**
 * @brief runCheckAffectedRows
 * @param conn
 * @param stmt
 * @param m_content
 */
void runCheckForQuery(MYSQL *conn, MYSQL_STMT *stmt, Content content) {
  long long affected_rows = mysql_stmt_affected_rows(stmt);
  const char *content_data; // confirmatio data to return
  const char *content_id;   // confirmatio data to return
  printf("\n\nInside the Action runCheckForQuery().\n");

  switch (content.oper_type) {
    //
  case OP_INSERT:
    printf("\n\nInside Oper INSERT.\n");

    //
    if (affected_rows == 1) {
      printf("User '%s' inserted successfully!\n", content.m_oper.field_name);
      printf("New user ID: %lld\n",
             (long long)mysql_stmt_insert_id(stmt)); // Get auto-increment ID
    } else {
      fprintf(stderr,
              "Error: No rows affected or more than one row affected.\n");
    }
    break;
  case OP_UPDATE:
    printf("\n\nInside Oper UPDATE.\n");

    //
    if (affected_rows > 0) {
      printf("User with ID %s updated successfully! Rows affected: %lld\n",
             content.m_oper.field_name, affected_rows);
    } else if (affected_rows == 0) {
      printf(
          "No user found with ID %s to update, or data was already the same.\n",
          content.m_oper.field_name);
    } else {
      // affected_rows can be -1 on error
      trateMySQLError(NULL, stmt);
    }
    break;
  case OP_DELETE:
    printf("\n\n******************************************");
    printf("\n           Action: DELETE               \n");
    printf("******************************************\n\n");
    if (affected_rows > 0) {
      printf("User with ID %s deleted successfully! Rows affected: %lld\n",
             content.m_oper.field_name, affected_rows);
      // content_id = content.m_oper.field_id; // get id
      //
      content_data = content.m_oper.field_name; // get author
      //

    } else if (affected_rows == 0) {
      printf("No user found with ID %s to delete.\n",
             content.m_oper.field_name);
    } else {
      trateMySQLError(NULL, stmt);
    }
    break;
  default:
    fprintf(stderr, "  Error: Unknown operation type for user ID %s\n",
            content.m_oper.field_name);
    return; // Indicate failure
  }

  // --- 7. Clean Up ---
  runCloseStmt(stmt); // Close the statement
  runCloseConn(conn); // Close the database connection
  printf("Connection closed.\n");
}
