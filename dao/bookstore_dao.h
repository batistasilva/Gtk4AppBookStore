#ifndef BOOKSTORE_DAO_H
#define BOOKSTORE_DAO_H

#include <mysql_utils.h>

//Create only for test with application without gtk4
// typedef struct
//       {
//     char book_id[100];
//     char title[100];
//     char author[100];
//     char genre[100];
//     char publication_date[200];
//     char isbn[100];
//     char price[100];
//     char rating[100];
//     char publisher[100];
//     char language[100];
//     char page_count[80];
// }BookData;


Content m_AddItemToDB(Content * content, int m_content_size);
Content m_UpdtItemToDB(Content * content, int m_content_size);
Content m_DeleteItemToDB(Content content);

#endif // BOOKSTORE_DAO_H
