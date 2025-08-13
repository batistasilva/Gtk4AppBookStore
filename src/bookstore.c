#include "../util-app/alert_handler.h"
#include <bookstore.h>
// #include <gtk/gtk.h> // Also include GTK header here for definitions

/**
 * @brief book_data_set_property
 * @param object
 * @param property_id
 * @param value
 * @param pspec
 */
static void book_data_set_property(GObject *object, guint property_id,
                                   const GValue *value, GParamSpec *pspec)

{
  BookData *self = BOOK_DATA(object);

  switch (property_id) {
  case PROP_BOOK_ID:
    self->book_id = g_value_dup_string(value);
    break;

  case PROP_TITLE:
    self->title = g_value_dup_string(value);
    break;

  case PROP_AUTHOR:
    self->author = g_value_dup_string(value);
    break;

  case PROP_GENRE:
    self->genre = g_value_dup_string(value);
    break;

  case PROP_PUBLICATION_DATE:
    self->publication_date = g_value_dup_string(value);
    break;

  case PROP_ISBN:
    self->isbn = g_value_dup_string(value);
    break;

  case PROP_PRICE:
    self->price = g_value_dup_string(value);
    break;

  case PROP_RATING:
    self->rating = g_value_dup_string(value);
    break;

  case PROP_PUBLISHER:
    self->publisher = g_value_dup_string(value);
    break;

  case PROP_LANGUAGE:
    self->language = g_value_dup_string(value);
    break;

  case PROP_PAGE_COUNT:
    self->page_count = g_value_dup_string(value);
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    break;
  }
}

static GParamSpec *properties[N_PROPS] = {
    NULL,
};
G_DEFINE_TYPE(BookData, book_data, G_TYPE_OBJECT)

/**
 * @brief book_data_get_property
 * @param object
 * @param property_id
 * @param value
 * @param pspec
 */
static void book_data_get_property(GObject *object, guint property_id,
                                   GValue *value, GParamSpec *pspec) {
  BookData *self = BOOK_DATA(object);

  switch (property_id) {
  case PROP_BOOK_ID:
    g_value_set_string(value, self->book_id);
    break;

  case PROP_TITLE:
    g_value_set_string(value, self->title);
    break;

  case PROP_AUTHOR:
    g_value_set_string(value, self->author);
    break;

  case PROP_GENRE:
    g_value_set_string(value, self->genre);
    break;

  case PROP_PUBLICATION_DATE:
    g_value_set_string(value, self->publication_date);
    break;

  case PROP_ISBN:
    g_value_set_string(value, self->isbn);
    break;

  case PROP_PRICE:
    g_value_set_string(value, self->price);
    break;

  case PROP_RATING:
    g_value_set_string(value, self->rating);
    break;

  case PROP_PUBLISHER:
    g_value_set_string(value, self->publisher);
    break;

  case PROP_LANGUAGE:
    g_value_set_string(value, self->language);
    break;

  case PROP_PAGE_COUNT:
    g_value_set_string(value, self->page_count);
    break;

  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID(object, property_id, pspec);
    break;
  }
}

/**
 * @brief book_data_finalize
 * @param object
 */
static void book_data_finalize(GObject *object) {
  BookData *self = BOOK_DATA(object);
  g_free(self->book_id);
  g_free(self->title);
  g_free(self->author);
  g_free(self->genre);
  g_free(self->publication_date);
  g_free(self->isbn);
  g_free(self->price);
  g_free(self->rating);
  g_free(self->publisher);
  g_free(self->language);
  g_free(self->page_count);
}

/**
 * @brief book_data_init
 * @param item
 */
static void book_data_init(BookData *item) {
  item->book_id = NULL;
  item->title = NULL;
  item->author = NULL;
  item->genre = NULL;
  item->publication_date = NULL;
  item->isbn = NULL;
  item->price = NULL;
  item->rating = NULL;
  item->publisher = NULL;
  item->language = NULL;
  item->page_count = NULL;
}

/**
 * @brief book_data_class_init
 * @param class
 */
static void book_data_class_init(BookDataClass *class) {
  GObjectClass *gobject_class = G_OBJECT_CLASS(class);

  gobject_class->finalize = book_data_finalize;
  gobject_class->get_property = book_data_get_property;
  gobject_class->set_property = book_data_set_property;

  properties[PROP_BOOK_ID] =
      g_param_spec_string("book_id", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_TITLE] =
      g_param_spec_string("title", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_AUTHOR] =
      g_param_spec_string("author", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_GENRE] =
      g_param_spec_string("genre", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_PUBLICATION_DATE] = g_param_spec_string(
      "publication_date", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_ISBN] =
      g_param_spec_string("isbn", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_PRICE] =
      g_param_spec_string("price", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_RATING] =
      g_param_spec_string("rating", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_PUBLISHER] =
      g_param_spec_string("publisher", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_LANGUAGE] =
      g_param_spec_string("language", NULL, NULL, NULL, G_PARAM_READWRITE);

  properties[PROP_PAGE_COUNT] =
      g_param_spec_string("page_count", NULL, NULL, NULL, G_PARAM_READWRITE);

  g_object_class_install_properties(gobject_class, N_PROPS, properties);
}

/**
 * @brief book_data_new
 * @param book_id
 * @param title
 * @param author
 * @param genre
 * @param publication_date
 * @param isbn
 * @param price
 * @param rating
 * @param publisher
 * @param language
 * @param page_count
 * @return
 */
static BookData *book_data_new(const char *book_id, const char *title,
                               const char *author, const char *genre,
                               const char *publication_date, const char *isbn,
                               const char *price, const char *rating,
                               const char *publisher, const char *language,
                               const char *page_count) {
  BookData *item = g_object_new(BOOK_TYPE_DATA, NULL);
  item->book_id = g_strdup(book_id);
  item->title = g_strdup(title);
  item->author = g_strdup(author);
  item->genre = g_strdup(genre);
  item->publication_date = g_strdup(publication_date);
  item->isbn = g_strdup(isbn);
  item->price = g_strdup(price);
  item->rating = g_strdup(rating);
  item->publisher = g_strdup(publisher);
  item->language = g_strdup(language);
  item->page_count = g_strdup(page_count);
  //
  return item;
}

/**
 * @brief create_book_model
 * @return
 */
GListModel *create_book_model(GListStore *store) {
  MYSQL *conn = runInitMySQL();

  conn = loadCnf(conn);

  const char *m_url = "SELECT * FROM book_store";

  MYSQL_RES *result = runQuery(conn, m_url);

  // int num_fields = getNumFields(result);

  MYSQL_ROW row;

//  store = g_list_store_new(G_TYPE_OBJECT);

  while ((row = getRowData(conn, result))) {
    g_list_store_append(store,
                        // id   ,title ,author,genre ,p-date,isbn, price
                        // ,rating, publish, lang, page
                        book_data_new(row[0], row[1], row[2], row[3], row[4],
                                      row[5], row[6], row[7], row[8], row[9],
                                      row[10]));
    printf("\n");
  }

  runCloseConn(conn);

  return G_LIST_MODEL(store);
}

/**
 * Populate the entry fields.
 * @brief setBookDataToEntry
 * @param m_book_data
 * @param mbbook_data
 */
void setBookDataToEntry(BookData *m_book_data, gpointer mbbook_data) {
  BuilderBook *builder_book = mbbook_data;
  //
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_book_id_obj),
                        m_book_data->book_id);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_title_obj),
                        m_book_data->title);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_author_obj),
                        m_book_data->author);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_genre_obj),
                        m_book_data->genre);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_publication_date_obj),
                        m_book_data->publication_date);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_isbn_obj),
                        m_book_data->isbn);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_price_obj),
                        m_book_data->price);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_rating_obj),
                        m_book_data->rating);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_publisher_obj),
                        m_book_data->publisher);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_language_obj),
                        m_book_data->language);
  gtk_editable_set_text(GTK_EDITABLE(builder_book->m_page_count_obj),
                        m_book_data->page_count);
  //Enable button remove and update
  gtk_widget_set_sensitive(GTK_WIDGET(builder_book->m_button_remove_obj), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(builder_book->m_button_update_obj), TRUE);
}

/**
 * Get all data from entry fields and add to model.
 * @brief getEntryToBookData
 * @param mbbook_data
 * @return
 */
BookData *getEntryToBookData(gpointer mbbook_data) {
  BuilderBook *m_build_data = mbbook_data;
  BookData *m_book_item = g_object_new(BOOK_TYPE_DATA, NULL);
  //
  m_book_item->book_id = g_strdup(
      gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_book_id_obj)));
  m_book_item->title =
      g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_title_obj)));
  m_book_item->author =
      g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_author_obj)));
  m_book_item->genre =
      g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_genre_obj)));
  m_book_item->publication_date = g_strdup(gtk_editable_get_text(
      GTK_EDITABLE(m_build_data->m_publication_date_obj)));
  m_book_item->isbn =
      g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_isbn_obj)));
  m_book_item->price =
      g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_price_obj)));
  m_book_item->rating =
      g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_rating_obj)));
  m_book_item->publisher = g_strdup(
      gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_publisher_obj)));
  m_book_item->language = g_strdup(
      gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_language_obj)));
  m_book_item->page_count = g_strdup(
      gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_page_count_obj)));

  //
  return m_book_item;
}

/**
 * @brief Load_Selectade_Item_Action
 * @param button
 * @param mbbook_data
 */
static void Load_Selectade_Item_Action(GtkButton *button,
                                       gpointer mbbook_data) {
  BuilderBook *build_data = mbbook_data;

  // GtkWidget *window;
  // window = gtk_window_new();

  g_print("\nRun Load Item...!!!");

  GtkSingleSelection *selection_model =
      GTK_SINGLE_SELECTION(gtk_column_view_get_model(build_data->columnview));

  guint selected_index = gtk_single_selection_get_selected(selection_model);

  if (selected_index != GTK_INVALID_LIST_POSITION) {
    BookData *book = gtk_single_selection_get_selected_item(selection_model);

    if (book) {
      g_print("\nGooing to set Bookdata to Entry.\n");

      // Populate the loaded data from model.
      setBookDataToEntry(book, build_data);

    } else {
      g_print("No valid item found at the selected index.\n");
    }
  } else {
    g_print("No row selected.\n");
  }
}

/**
 * @brief m_AddItemToDatabase
 * @param bookdata
 */
void m_AddItemToDatabase(BookData *bookdata, BuilderBook *build_book) {

  /*
      // Allocate memory for the array of pointers.
      Person* person_array = (Person*)malloc(sizeof(Person) * 1);//1 for one
     people

   */
  Content content_rs;
  Content *content = (Content *)malloc(sizeof(Content) * 10);

  safe_strcpy(content[0].m_oper.field_name, bookdata->title,
              sizeof(content[0].m_oper.field_name));
  safe_strcpy(content[0].type, "string", sizeof((const char *)"string"));
  //
  safe_strcpy(content[1].m_oper.field_name, bookdata->author,
              sizeof(content[1].m_oper.field_name));
  safe_strcpy(content[1].type, "string", sizeof((const char *)"string"));
  //
  content->oper_type = OP_INSERT;
  //
  safe_strcpy(content[2].m_oper.field_name, bookdata->genre,
              sizeof(content[2].m_oper.field_name));
  safe_strcpy(content[2].type, "string", sizeof((const char *)"string"));
  //
  safe_strcpy(content[3].m_oper.field_name, bookdata->isbn,
              sizeof(content[3].m_oper.field_name));
  safe_strcpy(content[3].type, "string", sizeof((const char *)"string"));
  //
  safe_strcpy(content[4].m_oper.field_name, bookdata->price,
              sizeof(content[4].m_oper.field_name));
  safe_strcpy(content[4].type, "string", sizeof((const char *)"string"));
  //
  safe_strcpy(content[5].m_oper.field_name, bookdata->rating,
              sizeof(content[5].m_oper.field_name));
  safe_strcpy(content[5].type, "string", sizeof((const char *)"string"));
  //
  safe_strcpy(content[6].m_oper.field_name, bookdata->publication_date,
              sizeof(content[6].m_oper.field_name));
  safe_strcpy(content[6].type, "string", sizeof((const char *)"string"));
  //
  safe_strcpy(content[7].m_oper.field_name, bookdata->publisher,
              sizeof(content[7].m_oper.field_name));
  safe_strcpy(content[7].type, "string", sizeof((const char *)"string"));
  //
  safe_strcpy(content[8].m_oper.field_name, bookdata->language,
              sizeof(content[8].m_oper.field_name));
  safe_strcpy(content[8].type, "string", sizeof((const char *)"string"));
  //
  safe_strcpy(content[9].m_oper.field_name, bookdata->page_count,
              sizeof(content[9].m_oper.field_name));
  safe_strcpy(content[9].type, "string", sizeof((const char *)"string"));
  //
  content_rs = m_AddItemToDB(content, 10);

  if (content_rs.m_oper.status) {
    runCleanToAllEntryFields(build_book);
    gtk_alert_show_info(content_rs.m_oper.sql_res_msg, build_book->window);
  } else {
    gtk_alert_show_error(content_rs.m_oper.sql_res_msg, build_book->window);
  }

  // clean allocate memory
  free(content);
}

/**
 * @brief m_RemoveItemToDatabase
 * @param build_book
 */
void m_RemoveItemToDatabase(BuilderBook *build_book)
{
  Content content_rs;
  Content content;

  const char *author_name =
      g_strdup(gtk_editable_get_text(GTK_EDITABLE(build_book->m_author_obj)));

  const char *book_id =
      g_strdup(gtk_editable_get_text(GTK_EDITABLE(build_book->m_book_id_obj)));

  safe_strcpy(content.m_oper.field_name, author_name,
              sizeof(content.m_oper.field_name));
  content.oper_type = OP_DELETE;
  content.m_oper.field_id = atoi(book_id);
  safe_strcpy(content.type, "int", sizeof("int"));
  //
  content_rs = m_DeleteItemToDB(content);

  if (content_rs.m_oper.status) {
    runCleanToAllEntryFields(build_book);
    gtk_alert_show_info(content_rs.m_oper.sql_res_msg, build_book->window);
  } else {
    gtk_alert_show_error(content_rs.m_oper.sql_res_msg, build_book->window);
  }
}

/**
 * @brief runCleanToAllEntryFields
 * @param build_book
 */
void runCleanToAllEntryFields(BuilderBook *build_book)
{
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_book_id_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_title_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_author_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_genre_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_publication_date_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_isbn_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_price_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_rating_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_publisher_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_language_obj), "");
  gtk_editable_set_text(GTK_EDITABLE(build_book->m_page_count_obj), "");
  //
  //Disable button remove and update
  gtk_widget_set_sensitive(GTK_WIDGET(build_book->m_button_remove_obj), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(build_book->m_button_update_obj), FALSE);
}

/**
 *
 * To retrieve your model and add new items from a GtkBuilder-loaded UI:
 *  GtkColumnView *view = GTK_COLUMN_VIEW(gtk_builder_get_object(builder,
 *  "column_view"));
 *  GtkSelectionModel *sel_model = gtk_column_view_get_model(view);
 *  GtkSingleSelection *single = GTK_SINGLE_SELECTION(sel_model);
 *  GListStore *store = G_LIST_STORE(gtk_single_selection_get_model(single));
 *  g_list_store_append(store, your_item);
 * @brief run_additem_callback
 * @param button
 * @param mbbook_data
 */
static void run_additem_callback(GtkButton *button, gpointer mbbook_data) {
  BuilderBook *m_build_data = mbbook_data;

  g_print("\nRun AddItem CallBack...!!!");

  GtkSelectionModel *selection_model =
      GTK_SELECTION_MODEL(gtk_column_view_get_model(m_build_data->columnview));

  /***
   * Get the Selected Item (for GtkSingleSelection): If using
   *GtkSingleSelection, retrieve the single selected item using
   *gtk_single_selection_get_selected_item().
   **/
  if (GTK_IS_SINGLE_SELECTION(selection_model)) {

    GtkSingleSelection *single_selection =
        GTK_SINGLE_SELECTION(selection_model);

    // Get the underlying GListModel
    GListModel *list_model = gtk_single_selection_get_model(single_selection);

    // Cast to GListStore
    GListStore *store = G_LIST_STORE(list_model);

    BookData *m_bookdata = getEntryToBookData(m_build_data);

    if (m_ValidEmptyFields(m_bookdata, m_build_data)) {

      // Add new item from fields to database
      m_AddItemToDatabase(m_bookdata, m_build_data);

      g_list_store_append(store, m_bookdata);
    }

    if (m_bookdata != NULL)
      g_object_unref(m_bookdata); // Store owns a reference now
  } else {
    gtk_alert_show_warning("There Is no single selection!", m_build_data->window);
  }

}

/**
 * @brief run_remove_item_callback
 * @param button
 * @param column_view
 */
static void run_remove_item_callback(GtkButton *button,
                                     gpointer mbbook_data)
{
  GtkWidget *window;
  BuilderBook *m_build_data = mbbook_data;

  g_print("\nRun Remove Item...!!!");

  GtkSingleSelection *selection_model =
      GTK_SINGLE_SELECTION(gtk_column_view_get_model(m_build_data->columnview));

  if (GTK_IS_SINGLE_SELECTION(selection_model)) {

    GtkSingleSelection *single_selection = GTK_SINGLE_SELECTION(selection_model);

    // Get the underlying GListModel
    GListModel *list_model = gtk_single_selection_get_model(single_selection);

    // Cast to GListStore
    GListStore *store = G_LIST_STORE(list_model);

    guint selected_index = gtk_single_selection_get_selected(selection_model);

    if (selected_index != GTK_INVALID_LIST_POSITION) {
      BookData *book = gtk_single_selection_get_selected_item(selection_model);

      if (book) {
        const char *message = "Do you want to remove this item?\n\t";
        gchar *msg = g_strconcat(message, "Name: ", book->author, NULL);

        // Create an alert dialog with a simple message and a callback
        int response = gtk_alert_ask(msg, GTK_WINDOW(m_build_data->window),
                                     "Yes", "Cancel");
        //Clean msg
        g_free(msg);

        if (response == GTK_RESPONSE_ACCEPT) {
          // Remove item to Database
          m_RemoveItemToDatabase(m_build_data);

          // Remove item to ColumnView
          g_list_store_remove(store, selected_index);

        }
      }
    } else {
      gtk_alert_show_warning("No row selected!", m_build_data->window);
    }
  }
}

/**
 * @brief m_UdateItemToDatabase
 * @param bookdata
 * @param build_book
 * @param parent
 */
void m_UdateItemToDatabase(BookData *bookdata,
                           BuilderBook *build_book)
{
  Content content_rs;
  Content *content = (Content *)malloc(sizeof(Content) * 11);
  //
  safe_strcpy(content[0].m_oper.field_name, bookdata->title,
              sizeof(content[0].m_oper.field_name));
  safe_strcpy(content[0].type, "string", sizeof("string"));
  //
  safe_strcpy(content[1].m_oper.field_name, bookdata->author,
              sizeof(content[1].m_oper.field_name));
  safe_strcpy(content[1].type, "string", sizeof("string"));
  content[1].oper_type = OP_UPDATE;
  //
  safe_strcpy(content[2].m_oper.field_name, bookdata->genre,
              sizeof(content[2].m_oper.field_name));
  safe_strcpy(content[2].type, "string", sizeof("string"));
  //
  safe_strcpy(content[3].m_oper.field_name, bookdata->isbn,
              sizeof(content[3].m_oper.field_name));
  safe_strcpy(content[3].type, "string", sizeof("string"));
  //
  safe_strcpy(content[4].m_oper.field_name, bookdata->price,
              sizeof(content[4].m_oper.field_name));
  safe_strcpy(content[4].type, "string", sizeof("string"));
  //
  safe_strcpy(content[5].m_oper.field_name, bookdata->rating,
              sizeof(content[5].m_oper.field_name));
  safe_strcpy(content[5].type, "string", sizeof("string"));
  //
  safe_strcpy(content[6].m_oper.field_name, bookdata->publication_date,
              sizeof(content[6].m_oper.field_name));
  safe_strcpy(content[6].type, "string", sizeof("string"));
  //
  safe_strcpy(content[7].m_oper.field_name, bookdata->publisher,
              sizeof(content[7].m_oper.field_name));
  safe_strcpy(content[7].type, "string", sizeof("string"));
  //
  safe_strcpy(content[8].m_oper.field_name, bookdata->language,
              sizeof(content[8].m_oper.field_name));
  safe_strcpy(content[8].type, "string", sizeof("string"));
  //
  safe_strcpy(content[9].m_oper.field_name, bookdata->page_count,
              sizeof(content[9].m_oper.field_name));
  safe_strcpy(content[9].type, "string", sizeof("string"));
  //
  content[10].m_oper.field_id = atoi(bookdata->book_id);
  safe_strcpy(content[10].type, "int", sizeof("int"));

  content_rs = m_UpdtItemToDB(content, 11);

  if (content_rs.m_oper.status) {
    runCleanToAllEntryFields(build_book);
    gtk_alert_show_info(content_rs.m_oper.sql_res_msg, build_book->window);
  } else {
    gtk_alert_show_error(content_rs.m_oper.sql_res_msg, build_book->window);
  }

  // clean allocate memory
  free(content);
}

/**
 * @brief run_update_item_callback
 * @param button
 * @param mbbook_data
 */
static void
run_update_item_callback(GtkButton *button,
                         gpointer mbbook_data)
{
  BuilderBook *m_build_data = mbbook_data;

  g_print("\nRun Update Item CallBack...!!!");

  GtkSelectionModel *selection_model =
      GTK_SELECTION_MODEL(gtk_column_view_get_model(m_build_data->columnview));
  /**
   * If item was selected, enter to work
   */
  if (GTK_IS_SINGLE_SELECTION(selection_model))
  {

    GtkSingleSelection *single_selection = GTK_SINGLE_SELECTION(selection_model);

    // Get the underlying GListModel
    GListModel *list_model = gtk_single_selection_get_model(single_selection);

    // Cast to GListStore
    GListStore *store = G_LIST_STORE(list_model);

    //Get position of item selected
    guint pos = gtk_single_selection_get_selected(single_selection);

    if (pos != GTK_INVALID_LIST_POSITION) {
      //
      BookData *m_bookdata = getEntryToBookData(m_build_data);

      //Get item store for position
      BookData *book_data = g_list_model_get_item(G_LIST_MODEL(store), pos);

      //Valid all required fields.
      if (m_ValidEmptyFields(m_bookdata, m_build_data)) {

         // Update item from fields to database
        m_UdateItemToDatabase(m_bookdata, m_build_data);

        /**
         * @brief m_UpdateItemToModel
         * It will update the selected data in
         * the model with the data, obtained from the field input.
         */
        m_UpdateItemToModel(book_data, m_bookdata);

        // g_object_set(book_data, "title", "New Book Title",
        //              NULL);   // or any other property

        // Don't forget to unref after get_item
        if (book_data  != NULL) g_object_unref(book_data);
        if (m_bookdata != NULL) g_object_unref(m_bookdata);
      }
    }

  } else {
    gtk_alert_show_warning("There is not single selection!", m_build_data->window);
  }

  g_print("\nEnd Update Item...!!!");
}

void book_mng_activate(GtkApplication *app, gpointer param) {

  g_autoptr(GtkBuilder) builder = NULL;

  // Load css file to style applications
  load_css(); //

  GListModel *model;
  GtkWidget *columnview;
  GtkListItemFactory *factory;
  GtkSingleSelection *selection;
  GtkColumnViewColumn *title_column;
  GtkColumnViewColumn *author_column;
  GtkColumnViewColumn *genre_column;
  GtkColumnViewColumn *rating_column;
  GtkColumnViewColumn *isbn_column;
  GtkColumnViewColumn *publication_date_column;
  GtkColumnViewColumn *price_column;
  GtkColumnViewColumn *publisher_column;
  GtkColumnViewColumn *language_column;
  GtkColumnViewColumn *page_count_column;
  BuilderBook *bbook_data;

  GtkSorter *sorter;
  GActionGroup *actions;
  GAction *action;

  // g_autoptr(GtkBuilder) builder = NULL;
  GtkWindow *main_window = GTK_WINDOW(param);

  /***
   * Ensure our custom object type is registered with the GObject system
   * before attempting to utilize it through GtkBuilder.
   **/
  g_type_ensure(BOOK_TYPE_DATA);

  builder = gtk_builder_new_from_file("../gui/gtkaddtolist.xml");

  /* Connect signal handlers to the constructed widgets. */
  GtkWindow *window =
      GTK_WINDOW(gtk_builder_get_object(builder, "main_window"));

  // Set the main window as parent
  gtk_window_set_transient_for(GTK_WINDOW(window), main_window);
  gtk_window_set_modal(GTK_WINDOW(window), TRUE);

  gtk_picture_new_for_filename("../gui/images/bookstore.png");

  g_object_add_weak_pointer(G_OBJECT(window), (gpointer *)&window);

  // Get the whole object that the application needs the builder.
  columnview = GTK_WIDGET(gtk_builder_get_object(builder, "column_view"));
  //
  GObject *obj_book_id = gtk_builder_get_object(builder, "entry_book_id");
  GObject *obj_title = gtk_builder_get_object(builder, "entry_title");
  GObject *obj_author = gtk_builder_get_object(builder, "entry_author");
  GObject *obj_genre = gtk_builder_get_object(builder, "entry_genre");
  GObject *obj_public_date =
      gtk_builder_get_object(builder, "entry_public_date");
  GObject *obj_isbn = gtk_builder_get_object(builder, "entry_isbn");
  GObject *obj_price = gtk_builder_get_object(builder, "entry_price");
  GObject *obj_rating = gtk_builder_get_object(builder, "entry_rating");
  GObject *obj_publisher = gtk_builder_get_object(builder, "entry_publisher");
  GObject *obj_language = gtk_builder_get_object(builder, "entry_language");
  GObject *obj_page_count = gtk_builder_get_object(builder, "entry_page_count");
  //
  GObject *obj_button_rm = gtk_builder_get_object(builder, "button_remove");
  GObject *obj_button_updt = gtk_builder_get_object(builder, "button_updt");
  selection =
  GTK_SINGLE_SELECTION(gtk_builder_get_object(builder, "single_select_model_id"));

 /***
  * Populate the columnview table with database data
  */
 g_object_bind_property_full(selection,
                             "selected-item",
                             columnview,
                             "model",
                             G_BINDING_SYNC_CREATE,
                             callPopulateColumnViewTable,
                             NULL,
                             columnview,
                             NULL);

 // Creat a stance the bookdata
 bbook_data = g_new(BuilderBook, 1);
 //
 bbook_data->window = window;
 bbook_data->columnview = GTK_COLUMN_VIEW(columnview);
 //
 bbook_data->m_book_id_obj = obj_book_id;
 bbook_data->m_title_obj = obj_title;
 bbook_data->m_author_obj = obj_author;
 bbook_data->m_genre_obj = obj_genre;
 bbook_data->m_publication_date_obj = obj_public_date;
 bbook_data->m_isbn_obj = obj_isbn;
 bbook_data->m_price_obj = obj_price;
 bbook_data->m_rating_obj = obj_rating;
 bbook_data->m_publisher_obj = obj_publisher;
 bbook_data->m_language_obj = obj_language;
 bbook_data->m_page_count_obj = obj_page_count;
 //
 bbook_data->m_button_remove_obj = obj_button_rm;
 bbook_data->m_button_update_obj = obj_button_updt;
 //
 //****************************************************************
 //       START SORT COLUMNS
 //****************************************************************

//For Column Title
 title_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_title"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "title")));
 //
 gtk_column_view_column_set_sorter(title_column, sorter);
 g_object_unref(sorter);

//For Column Author
 author_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_author"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "author")));
 //
 gtk_column_view_column_set_sorter(author_column, sorter);
 g_object_unref(sorter);

//For Column Genre
 genre_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_genre"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "genre")));
 //
 gtk_column_view_column_set_sorter(genre_column, sorter);
 g_object_unref(sorter);

//For Column Publication_date
 publication_date_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_publication_date"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "publication_date")));
 //
 gtk_column_view_column_set_sorter(publication_date_column, sorter);
 g_object_unref(sorter);

//For Column Isbn
 isbn_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_isbn"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "isbn")));
 //
 gtk_column_view_column_set_sorter(isbn_column, sorter);
 g_object_unref(sorter);

//For Column Price
 price_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_price"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "price")));
 //
 gtk_column_view_column_set_sorter(price_column, sorter);
 g_object_unref(sorter);


//For Column Rating
 rating_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_rating"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "rating")));
 //
 gtk_column_view_column_set_sorter(rating_column, sorter);
 g_object_unref(sorter);

//For Column Publisher
 publisher_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_publisher"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "publisher")));
 //
 gtk_column_view_column_set_sorter(publisher_column, sorter);
 g_object_unref(sorter);

//For Column Language
 language_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_language"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "language")));
 //
 gtk_column_view_column_set_sorter(language_column, sorter);
 g_object_unref(sorter);


//For Column Page_count
 page_count_column =
     GTK_COLUMN_VIEW_COLUMN(gtk_builder_get_object(builder, "column_page_count"));

 sorter = GTK_SORTER(gtk_string_sorter_new(
     gtk_property_expression_new(BOOK_TYPE_DATA, NULL, "page_count")));
 //
 gtk_column_view_column_set_sorter(page_count_column, sorter);
 g_object_unref(sorter);

 //*****************************************************************
 //               END SORT
 //*****************************************************************

 GObject *button_add = gtk_builder_get_object(builder, "button_add");

 g_signal_connect(GTK_BUTTON(button_add), "clicked",
                  G_CALLBACK(run_additem_callback), bbook_data);

 GObject *button_load = gtk_builder_get_object(builder, "button_load");

 g_signal_connect(GTK_BUTTON(button_load), "clicked",
                  G_CALLBACK(Load_Selectade_Item_Action), bbook_data);

 GObject *button_remove = gtk_builder_get_object(builder, "button_remove");

 g_signal_connect(GTK_BUTTON(button_remove), "clicked",
                  G_CALLBACK(run_remove_item_callback), bbook_data);

 GObject *button_updt = gtk_builder_get_object(builder, "button_updt");

 g_signal_connect(GTK_BUTTON(button_updt), "clicked",
                  G_CALLBACK(run_update_item_callback), bbook_data);

 GObject *button_clean = gtk_builder_get_object(builder, "button_clean");

 g_signal_connect(GTK_BUTTON(button_clean), "clicked",
                  G_CALLBACK(run_clean_entry_fields_callback), bbook_data);

 // gtk_application_add_window(app, window);
  gtk_window_present(GTK_WINDOW(window));
  //
 // g_object_unref(builder);
} // End Activate

/**
 * @brief run_clean_entry_fields_callback
 * @param button_clean
 * @param mbbook_data
 */
static void run_clean_entry_fields_callback(GtkButton *button_clean,
                                            gpointer mbbook_data) {
  BuilderBook *m_build_data = mbbook_data;

  runCleanToAllEntryFields(m_build_data);

}


/**
 * @brief m_ValidEmptyFields
 * @param bookdata
 * @return true or false
 */
bool m_ValidEmptyFields(BookData * bookdata,
                        BuilderBook *m_build_book)
{
  if (is_effectively_empty(bookdata->title)) {
    gtk_alert_show_warning("Field (Title) must be filled..!", m_build_book->window);
    return false;
}

  if (is_effectively_empty(bookdata->author)) {
    gtk_alert_show_warning("Field (Author) must be filled..!", m_build_book->window);
    return false;
  }

  if (is_effectively_empty(bookdata->genre)) {
    gtk_alert_show_warning("Field (Genre) must be filled..!", m_build_book->window);
    return false;
  }

  if (is_effectively_empty(bookdata->publication_date)) {
    gtk_alert_show_warning("Field (Publication date) must be filled..!", m_build_book->window);
    return false;
  }

  if (is_effectively_empty(bookdata->isbn)) {
    gtk_alert_show_warning("Field (Isbn) must be filled..!", m_build_book->window);
    return false;
  }

  if (is_effectively_empty(bookdata->price)) {
    gtk_alert_show_warning("Field (Price) must be filled..!", m_build_book->window);
    return false;
  }

  if (is_effectively_empty(bookdata->rating)) {
    gtk_alert_show_warning("Field (Rating) must be filled..!", m_build_book->window);
    return false;
  }

  if (is_effectively_empty(bookdata->publisher)) {
    gtk_alert_show_warning("Field (Publisher) must be filled..!", m_build_book->window);
    return false;
  }

  if (is_effectively_empty(bookdata->language)) {
    gtk_alert_show_warning("Field (Language) must be filled..!", m_build_book->window);
    return false;
  }

  if (is_effectively_empty(bookdata->page_count)) {
    gtk_alert_show_warning("Field (Page count) must be filled..!", m_build_book->window);
    return false;
  }

  return true;
}

static GtkFilter *current_filter;
gboolean
callPopulateColumnViewTable(GBinding *binding,
                           const GValue *from_value,
                           GValue *to_value,
                           gpointer columview)
{

    GListStore *store;
    GtkSortListModel *sort_model;
    GtkFilterListModel *filter_model;
    GtkFilter *filter;

  MYSQL *conn = runInitMySQL();

  conn = loadCnf(conn);

  const char *m_url = "SELECT * FROM book_store";

  MYSQL_RES *result = runQuery(conn, m_url);

  // int num_fields = getNumFields(result);

  MYSQL_ROW row;

  /*
     Create a new GListStore to hold
     'BOOK_TYPE_DATA' objects.
  */
  store = g_list_store_new(BOOK_TYPE_DATA);

  while ((row = getRowData(conn, result))) {
    g_list_store_append(store,
                        // id   ,title ,author,genre ,p-date,isbn, price
                        // ,rating, publish, lang, page
                        book_data_new(row[0], row[1], row[2], row[3], row[4],
                                      row[5], row[6], row[7], row[8], row[9],
                                      row[10]));
  }

  runCloseConn(conn);


    sort_model = gtk_sort_list_model_new(
        G_LIST_MODEL(store),
        g_object_ref(gtk_column_view_get_sorter(GTK_COLUMN_VIEW(columview))));

    filter = GTK_FILTER(gtk_string_filter_new(
            gtk_property_expression_new(BOOK_TYPE_DATA,
                                        NULL,
                                        "title")));

    g_set_object(&current_filter, filter);

    filter_model = gtk_filter_list_model_new(
        G_LIST_MODEL(sort_model),
        filter);

    g_value_take_object(to_value, gtk_single_selection_new(G_LIST_MODEL(filter_model)));

    return TRUE;
}

/**
 * @brief load_css
 */
void load_css(void) {
  GtkCssProvider *provider = gtk_css_provider_new();
  gtk_css_provider_load_from_path(provider, "../gui/css/style.css");

  gtk_style_context_add_provider_for_display(
      gdk_display_get_default(), GTK_STYLE_PROVIDER(provider),
      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

  g_object_unref(provider);
}


/**
 * @brief m_UpdateItemToModel
 * @param book_data_old
 * @param book_data_new
 */
void
m_UpdateItemToModel(BookData *book_data_old,
                         BookData *book_data_new)
{
        g_object_set(book_data_old, "title",book_data_new->title,
                                "author",book_data_new->author,
                                "genre",book_data_new->genre,
                                 "publication_date", book_data_new->publication_date,
                                 "isbn",book_data_new->isbn,
                                 "price",book_data_new->price,
                                 "rating", book_data_new->rating,
                                 "publisher", book_data_new->publisher,
                                 "language", book_data_new->language,
                                 "page_count", book_data_new->page_count,NULL);
}
