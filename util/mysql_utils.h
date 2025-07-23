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

/**
 * @brief The Content class
 */
struct Content {
    char *type;
    char *value;
    int value_int;
};



// Initializes MySQL connection handle
/**
 * @brief runInitMySQL
 * @return
 */
MYSQL *runInitMySQL(void);

// Loads config from .cnf and connects
/**
 * @brief loadCnf
 * @param m_conn
 * @return
 */
MYSQL *loadCnf(MYSQL *conn);

// Executes a fixed query and returns result set
/**
 * @brief runQuery
 * @param conn
 * @param m_url
 * @return
 */
MYSQL_RES *runQuery(MYSQL *conn, const char *m_url);

/**
 * @brief getFieldValue
 * @param row
 * @param index
 * @return
 */
const char *getFieldValue(MYSQL_ROW row, unsigned int index);

/**
 * @brief getFieldValueSafe
 * @param row
 * @param index
 * @param fieldCount
 * @return
 */
const char *getFieldValueSafe(MYSQL_ROW row, unsigned int index,
                              unsigned int fieldCount);
/**
 * @brief getRowData
 * @param conn
 * @param result
 * @return
 */
MYSQL_ROW getRowData(MYSQL *conn, MYSQL_RES *result);

/**
 * @brief getNumFields
 * @param result
 * @return
 */
int getNumFields(MYSQL_RES *result);

/**
 * @brief printFieldNames
 * @param result
 */
void printFieldNames(MYSQL_RES *result);


/**
 * @brief printConnError
 * @param conn
 * @param message
 */
void printConnError(MYSQL *conn, const char *message);

/**
 * @brief printStmtError
 * @param stmt
 * @param message
 */
void printStmtError(MYSQL_STMT *stmt, const char *message);

// Initializes MySQL connection handle
/**
 * @brief runInitMySQL
 * @return
 */
MYSQL *runInitMySQL(void);

// Loads config from .cnf and connects
/**
 * @brief loadCnf
 * @param m_conn
 * @return
 */
MYSQL *loadCnf(MYSQL *m_conn);

// Executes a fixed query and returns result set
/**
 * @brief runQuery
 * @param conn
 * @param m_url
 * @return
 */
MYSQL_RES *runQuery(MYSQL *conn, const char *m_url);

/**
 * @brief runStmtInit
 * @param stmt
 * @param conn
 * @return
 */
MYSQL_STMT * runStmtInit(MYSQL_STMT * stmt, MYSQL *conn);

/**
 * @brief runStmtPrep
 * @param conn
 * @param stmt
 * @param sql_insert
 * @return
 */
int runStmtPrep(MYSQL *conn, MYSQL_STMT * stmt, const char *sql_insert);

/**
 * @brief runStmtBind
 * @param conn
 * @param stmt
 * @param content
 * @param content_size
 * @return
 */
int runStmtBind(MYSQL *conn,
                MYSQL_STMT *stmt,
                struct Content *content,
                int content_size
                );

/**
 * @brief runSQLExec
 * @param conn
 * @param stmt
 * @param content
 * @return
 */
int runSQLExec(MYSQL *conn,
               MYSQL_STMT *stmt,
               struct Content *content);

/**
 * @brief runCheckAffectedRows
 * @param conn
 * @param stmt
 * @param m_content
 */
void runCheckAffectedRows(MYSQL *conn,
                          MYSQL_STMT *stmt,
                          struct Content *m_content);

/**
 * Safely closes a MySQL connection and frees a result set if provided.
 *
 * Parameters:
 *   conn   - A pointer to a MYSQL connection. Can be NULL.
 *   result - A pointer to a MYSQL_RES result set. Can be NULL.
 *   stmt - A pointer to a MYSQL_STMT connection. Can be NULL.
 *
 * This function checks for NULL values before freeing the result or
 * closing the connection.
 * It is safe to call with either parameter as NULL.
 *
 * Note:
 *   Always call this after you're done using the result and connection to
 *   prevent memory leaks.
 */

static inline void runCloseConn(MYSQL *conn)
{
    if (conn)mysql_close(conn);
}

static inline void runCloseStmt(MYSQL_STMT *stmt)
{
    if (stmt) mysql_stmt_close(stmt);
}

/**
 * @brief secure_memset
 * @param s
 * @param c
 * @param n
 */
static inline void secure_memset(void *s, int c, size_t n) {
    volatile unsigned char *p = (volatile unsigned char *)s;
    while (n--) {
        *p++ = (unsigned char)c;
    }
}

/**
 * @brief getFieldValue
 * @param row
 * @param index
 * @return
 */
const char *getFieldValue(MYSQL_ROW row, unsigned int index);

/**
 * @brief getFieldValueSafe
 * @param row
 * @param index
 * @param fieldCount
 * @return
 */
const char *getFieldValueSafe(MYSQL_ROW row, unsigned int index,
                              unsigned int fieldCount);

/**
 * @brief getNumFields
 * @param result
 * @return
 */
int getNumFields(MYSQL_RES *result);

/**
 * @brief printFieldNames
 * @param result
 */
void printFieldNames(MYSQL_RES *result);


#ifdef __cplusplus
}
#endif

#endif // MYSQL_UTILS_H
