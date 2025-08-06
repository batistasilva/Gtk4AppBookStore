#ifndef BOOK_STRUCT_UTIL_H
#define BOOK_STRUCT_UTIL_H
#include <gtk/gtk.h>
#include <glib/gi18n.h>
#include <gtk-4.0/gtk/gtkbuilder.h>

/**
  This is to send the BUILDER OBJ to other functions.
  This way I can set data to the input fields,
  I can also load, define and delete data from the
  ColumnView model.
 **/
typedef struct {
    GtkColumnView * columnview;
    GtkWindow * window;
    GObject * m_book_id_obj;
    GObject * m_title_obj;
    GObject * m_author_obj;
    GObject * m_genre_obj;
    GObject * m_publication_date_obj;
    GObject * m_isbn_obj;
    GObject * m_price_obj;
    GObject * m_rating_obj;
    GObject * m_publisher_obj;
    GObject * m_language_obj;
    GObject * m_page_count_obj;
    //
    GObject * m_button_remove_obj;
    GObject * m_button_update_obj;

} BuilderBook;

// typedef struct {
//     GListStore *store;
//     guint selected_index;
//     BuilderBook * build_book;
// } ItemToRemove;

#endif // BOOK_STRUCT_UTIL_H
