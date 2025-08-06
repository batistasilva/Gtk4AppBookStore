#include <bookstore_dao.h>

/**
 * @brief m_AddItemToDB
 * @param new_content
 * @param m_content_size
 * @return struct Content *
 ***/
Content m_AddItemToDB(Content *content, int m_content_size) {
  Content content_rs;
  MYSQL *conn = NULL;
  MYSQL_STMT *stmt = NULL;
  conn = runInitMySQL();

  if(content == NULL)
     ERROR_LOG("Failed to Content..");

  // Define operation to get result correct
  content->oper_type = OP_INSERT;

  conn = loadCnf(conn);

  printf("Successfully connected to MariaDB!\n");

  // Use placeholders (?) for values to prevent SQL injection
  const char *sql_insert =
      "INSERT INTO book_store (title, author, genre, isbn, price, "
      "rating, publication_date, publisher, language, page_count) "
      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

  stmt = runStmtInit(stmt, conn);

  if (runStmtPrep(conn, stmt, sql_insert))
  {
    trateMySQLError(conn, stmt);
    ERROR_LOG("runStmtPrep() Error: %s", "mysql_stmt_prepare() failed");
  }
  printf("SQL statement prepared successfully.\n");

  // Add content and you length to bind
  runStmtBindToArrayOfContent(conn, stmt, content, m_content_size);

  // Execute the insertion in database
  runSQLExec(conn, stmt, content[1]); // content[1] to Item number of 1 for array

  // Check return of insertion
  content_rs = runCheckAffectedRows(
      conn, stmt, content[1]); // content[1] to Item number of 1 for array

  return content_rs;
}

/**
 * @brief m_UpdtItemToDB
 * @param updt_content
 * @param m_content_size
 * @return Content *
 **/
Content m_UpdtItemToDB(Content *content, int m_content_size) {
  Content content_rs;
  MYSQL *conn = NULL;
  MYSQL_STMT *stmt = NULL;
  conn = runInitMySQL();
  conn = loadCnf(conn);
  ShowMessage("Inside m_UpdtItemDB()", 1, 2);

  // Define operation to get result correctly

  printf("\nValue-1 from Option1: %d    Value from Option2: %d\n",
         content->oper_type, content_rs.oper_type);

  printf("Successfully connected to MariaDB!\n");

  // Use placeholders (?) for values to prevent SQL injection

  const char *sql_update =
      "UPDATE book_store SET title=?, author=?, genre=?, isbn=?, "
      "price=?, rating=?, publication_date=?, publisher=?, language=?, "
      "page_count=? WHERE book_id=?";

  stmt = runStmtInit(stmt, conn);

  if (runStmtPrep(conn, stmt, sql_update)) {
    trateMySQLError(conn, stmt);
  }

  printf("SQL statement prepared successfully.\n");

  //  // Calculate the number of elements in the array
  // int numElements = sizeof(content) / sizeof(content[0]);

  // Add content and you length to bind
  runStmtBindToArrayOfContent(conn, stmt, content, m_content_size);
  printf("End runStmtBind. \n");

  // Execute the insertion in database
  runSQLExec(conn, stmt, content[1]); // content[1] for fieldname
                                      // array
  printf("End runSQLExec. \n");

  //Set book_id to return it
  content[1].m_oper.field_id = content[10].m_oper.field_id;

  // Check return of insertion
  content_rs = runCheckAffectedRows(conn, stmt, content[1]); // content[1] to Item number of 1 for array
  printf("End runCheckAffectedRows. \n");

  return content_rs;
}

/**
 * @brief m_DeleteItemToDB
 * @param content
 * @param m_content_size
 * @return struct Content *
 **/
Content m_DeleteItemToDB(Content content) {
  Content content_rs;
  //
  MYSQL *conn = NULL;
  MYSQL_STMT *stmt = NULL;
  conn = runInitMySQL();
  if (conn == NULL) {
    fprintf(stderr, "mysql_init() failed\n");
    //    return;
  }
  printf("m_DeleteItemToDB()\n");

  conn = loadCnf(conn);

  char *str_error = (char *)stderr;

  printf("Successfully connected to MariaDB!\n");

  // Use placeholders (?) for values to prevent SQL injection
  const char *sql_delete = "DELETE FROM book_store WHERE book_id=?";

  printf("\n\nSQL Query..: %s.\n", sql_delete);

  stmt = runStmtInit(stmt, conn);

  if (runStmtPrep(conn, stmt, sql_delete)) {
    trateMySQLError(conn, stmt);
  }

  printf("\n\nSQL statement prepared successfully.\n");

  // Add content and you length to bind
  runStmtBindToContent(conn, stmt, content);

  printf("End runStmtBind. \n");

  // Execute the insertion in database
  runSQLExec(conn, stmt, content);
  printf("\nEnd runSQLExec. \n");

  // Check return of insertion
  // runCheckForQuery(conn, stmt, content);//to test
  content_rs = runCheckAffectedRows(conn, stmt, content);

  printf("End runCheckAffectedRows. \n");
  return content_rs;
}

// // This function is safe and avoids the warning.
// struct Content* m_DeleteItemToDB_safe(struct Content* content) {
//     // Check for a valid input first (best practice)
//     if (content == NULL) {
//  //       fprintf(stderr, "Error: Content pointer is NULL.\n");
//         return NULL;
//     }

//     // Logic to delete the item from the database.
//     // Let's assume a function 'database_delete' handles this.
//     // For this example, we'll simulate success and failure.
//     int success = (content->m_oper->field_id!= 0); // Example condition

//     if (success) {
//         printf("Item with ID %d deleted successfully.\n",
//         content->m_oper->field_id);
//         // Return the pointer to the deleted content on success.
//         // The calling function will need to free this memory later.
//         return content;
//     } else {
//  //       fprintf(stderr, "Error: Could not delete item with ID %d.\n",
//  content->m_oper->field_id);
//         // Explicitly return NULL on failure.
//         return NULL;
//     }
// }
