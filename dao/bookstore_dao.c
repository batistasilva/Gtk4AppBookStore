#include <bookstore_dao.h>

/**
 * @brief m_AddItemToDB
 * @param new_content
 * @param m_content_size
 */
void m_AddItemToDB(struct Content *new_content, int m_content_size)
{
  MYSQL *conn = NULL;
  MYSQL_STMT *stmt = NULL;
  conn = runInitMySQL();

  //Define operation to get result correct
  new_content->oper_type = OP_INSERT;

  conn = loadCnf(conn);

  printf("Successfully connected to MariaDB!\n");

  // Use placeholders (?) for values to prevent SQL injection
  const char *sql_insert =
  "INSERT INTO book_store (title, author, genre, isbn, price, "
  "rating, publication_date, publisher, language, page_count) "
                        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

  stmt = runStmtInit(stmt, conn);

  if (runStmtPrep(conn, stmt, sql_insert)) {
     printConnError(conn, "mysql_conn() failed");
     printStmtError(stmt, "mysql_stmt_prepare() failed");
  }

  printf("SQL statement prepared successfully.\n");

  //  // Calculate the number of elements in the array
  //int numElements = sizeof(content) / sizeof(content[0]);

  //Add content and you length to bind
  runStmtBind(conn, stmt, new_content, m_content_size);

  //Execute the insertion in database
  runSQLExec(conn, stmt, new_content);

  //Check return of insertion
  runCheckAffectedRows(conn, stmt, new_content);

}

/**
 * @brief m_UpdtItemToDB
 * @param updt_content
 * @param m_content_size
 */
void m_UpdtItemToDB(struct Content *updt_content, int m_content_size)
{
  MYSQL *conn = NULL;
  MYSQL_STMT *stmt = NULL;
  conn = runInitMySQL();
  conn = loadCnf(conn);

  //Define operation to get result correct
  updt_content->oper_type = OP_UPDATE;

  printf("Successfully connected to MariaDB!\n");

  // Use placeholders (?) for values to prevent SQL injection

   const char *sql_update =
  "UPDATE book_store SET title=?, author=?, genre=?, isbn=?, "
  "price=?, rating=?, publication_date=?, publisher=?, language=?, "
  "page_count=? WHERE book_id=?";

  stmt = runStmtInit(stmt, conn);

  if (runStmtPrep(conn, stmt, sql_update)) {
     printConnError(conn, "mysql_conn() failed");
     printStmtError(stmt, "mysql_stmt_prepare() failed");
  }

  printf("SQL statement prepared successfully.\n");

  //  // Calculate the number of elements in the array
  //int numElements = sizeof(content) / sizeof(content[0]);

  //Add content and you length to bind
  runStmtBind(conn, stmt, updt_content, m_content_size);
  printf("End runStmtBind. \n");

  //Execute the insertion in database
  runSQLExec(conn, stmt, updt_content);
  printf("End runSQLExec. \n");

  //Check return of insertion
  runCheckAffectedRows(conn, stmt, updt_content);
  printf("End runCheckAffectedRows. \n");

}

/**
 * @brief m_DeleteItemToDB
 * @param content
 * @param m_content_size
 */
void m_DeleteItemToDB(struct Content *content, int m_content_size)
{
  MYSQL *conn = NULL;
  MYSQL_STMT *stmt = NULL;
  conn = runInitMySQL();
  conn = loadCnf(conn);

  //Define operation to get result correct
  content->oper_type = OP_DELETE;

  printf("Successfully connected to MariaDB!\n");

  // Use placeholders (?) for values to prevent SQL injection
   const char *sql_delete = "DELETE FROM book_store WHERE book_id=?";

  stmt = runStmtInit(stmt, conn);

  if (runStmtPrep(conn, stmt, sql_delete)) {
     printConnError(conn, "mysql_conn() failed");
     printStmtError(stmt, "mysql_stmt_prepare() failed");
  }

  printf("SQL statement prepared successfully.\n");

  //Add content and you length to bind
  runStmtBind(conn, stmt, content, m_content_size);
  printf("End runStmtBind. \n");

  //Execute the insertion in database
  runSQLExec(conn, stmt, content);
  printf("End runSQLExec. \n");

  //Check return of insertion
  runCheckAffectedRows(conn, stmt, content);
  printf("End runCheckAffectedRows. \n");
}
