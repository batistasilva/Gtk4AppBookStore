#ifndef MYSQL_UTILS_H
#define MYSQL_UTILS_H

#include <mariadb/mysql.h>

#ifdef _WIN32
#define DEFAULT_MYSQL_CNF_PATH "C:/ProgramData/MySQL/MySQL Server 8.0/my.cnf"
#else
#define DEFAULT_MYSQL_CNF_PATH "../../dao/my.cnf" // for app folder
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Initializes MySQL connection handle
MYSQL *RunInitMySQL(void);

// Loads config from .cnf and connects
MYSQL *LoadMyCNF(MYSQL *conn);

// Executes a fixed query and returns result set
MYSQL_RES *m_RunQuery(MYSQL *conn, const char *Url);

/**
 * Safely closes a MySQL connection and frees a result set if provided.
 *
 * Parameters:
 *   conn   - A pointer to a MYSQL connection. Can be NULL.
 *   result - A pointer to a MYSQL_RES result set. Can be NULL.
 *
 * This function checks for NULL values before freeing the result or
 * closing the connection.
 * It is safe to call with either parameter as NULL.
 *
 * Note:
 *   Always call this after you're done using the result and connection to
 *   prevent memory leaks.
 */
static inline void runCloseConn(MYSQL *conn, MYSQL_RES *result) {
    if (result)
        mysql_free_result(result);
    if (conn)
        mysql_close(conn);
}

// Centralized error handling
void finish_with_error(MYSQL *conn);

const char *getFieldValue(MYSQL_ROW row, unsigned int index);

const char *getFieldValueSafe(MYSQL_ROW row, unsigned int index,
                              unsigned int fieldCount);

MYSQL_ROW getRowData(MYSQL_RES *result);

int getNumFields(MYSQL_RES *result);

void printFieldNames(MYSQL_RES *result);

#ifdef __cplusplus
}
#endif

#endif // MYSQL_UTILS_H
