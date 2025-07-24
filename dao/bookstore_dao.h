#ifndef BOOKSTORE_DAO_H
#define BOOKSTORE_DAO_H
#include <mysql_utils.h>

void m_AddItemToDB(struct Content * new_content, int m_content_size);
void m_UpdtItemToDB(struct Content * updt_content, int m_content_size);
void m_DeleteItemToDB(struct Content * content, int m_content_size);

#endif // BOOKSTORE_DAO_H
