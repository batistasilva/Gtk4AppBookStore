#include "mysql_utils.h"
#include <stdio.h>
#include <stdlib.h>


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
void finish_with_error(MYSQL *conn) {
    if (conn) {
        fprintf(stderr, "MySQL error: %s\n", mysql_error(conn));
        runCloseConn(conn, NULL);
    } else {
        fputs("MySQL connection is NULL\n", stderr);
    }
    exit(EXIT_FAILURE);
}

/**
 * Initializes a new MySQL connection handle.
 *
 * Returns:
 *   A pointer to a new MYSQL object.
 *   Exits the program with an error if
 *   initialization fails.
 */
MYSQL *RunInitMySQL() {
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        fputs("Error: mysql_init() failed\n", stderr);
        exit(EXIT_FAILURE);  // Or call a centralized handler if available
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
MYSQL *LoadMyCNF(MYSQL *conn) {
    if (conn == NULL) {
        fputs("Error: NULL MySQL connection passed to LoadMyCNF()\n", stderr);
        return NULL;
    }

    const char *cnf_path = getenv("MYSQL_CNF_PATH");
    if (cnf_path == NULL) {
        fprintf(stderr, "MYSQL_CNF_PATH not set, using default: %s\n", DEFAULT_MYSQL_CNF_PATH);
        cnf_path = DEFAULT_MYSQL_CNF_PATH;
    }

    if (mysql_options(conn, MYSQL_READ_DEFAULT_FILE, cnf_path) != 0) {
        fprintf(stderr, "mysql_options() failed: %s\n", mysql_error(conn));
        mysql_close(conn);
        return NULL;
    }

    if (!mysql_real_connect(conn, NULL, NULL, NULL, NULL, 0, NULL, CLIENT_FOUND_ROWS)) {
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
MYSQL_RES *m_RunQuery(MYSQL *conn, const char *Url) {
    MYSQL *m_con = conn;

    if (mysql_query(m_con, Url)) {
        finish_with_error(m_con);
    }

    MYSQL_RES *result = mysql_store_result(m_con);
    if (result == NULL) {
        finish_with_error(m_con);
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
 *   Each row is an array of strings (char*), with NULL fields represented as NULL.
 *
 * Note:
 *   The returned MYSQL_ROW pointer is invalidated by the next call to
 *   mysql_fetch_row() or by calling mysql_free_result().
 */
MYSQL_ROW getRowData(MYSQL_RES *result){
    MYSQL_ROW row;

    if (result == NULL) {
        runCloseConn(NULL, result);
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
 *   It assumes that the index is within the range returned by mysql_num_fields().
 */
const char *getFieldValue(MYSQL_ROW row, unsigned int index) {
    if (!row) return "NULL";
    return row[index] ? row[index] : "NULL";
}

const char *getFieldValueSafe(MYSQL_ROW row, unsigned int index, unsigned int fieldCount) {
    if (!row || index >= fieldCount) return "NULL";
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
    if (!result) return -1;
    return (int) mysql_num_fields(result);
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
    if (!result) return;

    unsigned int num_fields = mysql_num_fields(result);
    MYSQL_FIELD *fields = mysql_fetch_fields(result);

    for (unsigned int i = 0; i < num_fields; ++i) {
        printf("%s\t", fields[i].name);
    }
    printf("\n");
}


