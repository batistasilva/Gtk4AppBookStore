#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include <book-struct-util.h>
#include <bookstore_dao.h>
#include <alert_handler.h>
#include <util.h>
#include <gtk/gtk.h> // Also include GTK header here for definitions

G_GNUC_BEGIN_IGNORE_DEPRECATIONS


#define BOOK_TYPE_DATA (book_data_get_type ())

typedef struct _BookData BookData;

G_DECLARE_FINAL_TYPE(BookData, book_data, BOOK, DATA, GObject)
static gboolean result_remove_item = false;

enum
{
    PROP_0,
    PROP_BOOK_ID,
    PROP_TITLE,
    PROP_AUTHOR,
    PROP_GENRE,
    PROP_PUBLICATION_DATE,
    PROP_ISBN,
    PROP_PRICE,
    PROP_RATING,
    PROP_PUBLISHER,
    PROP_LANGUAGE,
    PROP_PAGE_COUNT,
    N_PROPS
};

struct
    _BookData {
    GObject parent_instance;
    char *book_id;
    char *title;
    char *author;
    char *genre;
    char *publication_date;
    char *isbn;
    char *price;
    char *rating;
    char *publisher;
    char *language;
    char *page_count;
};

struct _BookDataClass {
    GObjectClass parent_class;
};


static void
book_data_set_property (GObject *object,
                       guint property_id,
                       const GValue *value,
                       GParamSpec *pspec);



static void
book_data_get_property (GObject *object,
                       guint property_id,
                       GValue *value,
                       GParamSpec *pspec);

static void
book_data_finalize (GObject *object);

static void
book_data_init(BookData *item);

static void
book_data_class_init(BookDataClass * class);


static
    BookData * book_data_new (
                  const char *book_id,
                  const char *title,
                  const char *author,
                  const char *genre,
                  const char *publication_date,
                  const char *isbn,
                  const char *price,
                  const char *rating,
                  const char *publisher,
                  const char *language,
                               const char *page_count);

// a funktion that creates a GListModel with capital_item  objects
GListModel *
create_book_model(void);


// Response handler to handle OK/Cancel actions
static void
on_response_remove(GtkAlertDialog *dialog,
                   gint response,
                   gpointer user_data);

// static void
// show_alert_dialog(GtkWindow *parent_window,
//                   const char *message,
//                   GCallback on_sl_response,
//                   gpointer ok_data,
//                   ItemToRemove * mitem);

void setBookDataToEntry(BookData * m_book_data, gpointer mbbook_data);


BookData * getEntryToBookData(gpointer mbbook_data);

static void
Load_Selectade_Item_Action(GtkButton *button,
                           gpointer mbbook_data);


static void run_additem_callback(GtkButton *button,
                                 gpointer mbbook_data);

static void
run_remove_item_callback(GtkButton *button, gpointer mbbook_data);

static void
run_clean_entry_fields_callback(GtkButton *button, gpointer mbbook_data);


void
activate(GtkApplication *app, gpointer user_data);

void m_AddItemToDatabase(BookData * bookdata,
                         BuilderBook *build_book);

void m_UdateItemToDatabase(BookData * bookdata,
                           BuilderBook *build_book);

bool m_ValidEmptyFields(BookData * bookdata);

void m_RemoveItemToDatabase(BuilderBook * build_book);

void runCleanToAllEntryFields(BuilderBook *build_book);

#endif // BOOKSTORE_H
