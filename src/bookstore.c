#include <bookstore.h>

/**
 * @brief book_data_set_property
 * @param object
 * @param property_id
 * @param value
 * @param pspec
 */
static void
book_data_set_property (GObject *object,
                       guint property_id,
                       const GValue *value,
                       GParamSpec *pspec)

{
    BookData *self = BOOK_DATA(object);

    switch (property_id)
    {
    case PROP_TITLE:
        self->title = g_value_dup_string (value);
        break;

    case PROP_AUTHOR:
        self->author = g_value_dup_string (value);
        break;

    case PROP_GENRE:
        self->genre = g_value_dup_string (value);
        break;

    case PROP_PUBLICATION_DATE:
        self->publication_date = g_value_dup_string (value);
        break;

    case PROP_ISBN:
        self->isbn = g_value_dup_string (value);
        break;

    case PROP_PRICE:
        self->price = g_value_dup_string (value);
        break;

    case PROP_RATING:
        self->rating = g_value_dup_string (value);
        break;

    case PROP_PUBLISHER:
        self->publisher = g_value_dup_string (value);
        break;

    case PROP_LANGUAGE:
        self->language = g_value_dup_string (value);
        break;

    case PROP_PAGE_COUNT:
        self->page_count = g_value_dup_string (value);
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
        break;
    }

}

static GParamSpec *properties[N_PROPS] = {NULL,};
G_DEFINE_TYPE(BookData, book_data, G_TYPE_OBJECT)

/**
 * @brief book_data_get_property
 * @param object
 * @param property_id
 * @param value
 * @param pspec
 */
static void
book_data_get_property (GObject *object,
                       guint property_id,
                       GValue *value,
                       GParamSpec *pspec)
{
    BookData *self = BOOK_DATA(object);

    switch (property_id)
    {
    case PROP_TITLE:
        g_value_set_string (value, self->title);
        break;

    case PROP_AUTHOR:
        g_value_set_string (value, self->author);
        break;

    case PROP_GENRE:
        g_value_set_string (value, self->genre);
        break;

    case PROP_PUBLICATION_DATE:
        g_value_set_string (value, self->publication_date);
        break;

    case PROP_ISBN:
        g_value_set_string (value, self->isbn);
        break;

    case PROP_PRICE:
        g_value_set_string (value, self->price);
        break;

    case PROP_RATING:
        g_value_set_string (value, self->rating);
        break;

    case PROP_PUBLISHER:
        g_value_set_string (value, self->publisher);
        break;

    case PROP_LANGUAGE:
        g_value_set_string (value, self->language);
        break;

    case PROP_PAGE_COUNT:
        g_value_set_string (value, self->page_count);
        break;

    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
        break;
    }
}

/**
 * @brief book_data_finalize
 * @param object
 */
static void
book_data_finalize (GObject *object)
{
    BookData *self = BOOK_DATA(object);

    g_free (self->title);
    g_free (self->author);
    g_free (self->genre);
    g_free (self->publication_date);
    g_free (self->isbn);
    g_free (self->price);
    g_free (self->rating);
    g_free (self->publisher);
    g_free (self->language);
    g_free (self->page_count);
}

/**
 * @brief book_data_init
 * @param item
 */
static void
book_data_init(BookData *item) {
    item->title            = NULL;
    item->author           = NULL;
    item->genre            = NULL;
    item->publication_date = NULL;
    item->isbn             = NULL;
    item->price            = NULL;
    item->rating           = NULL;
    item->publisher        = NULL;
    item->language         = NULL;
    item->page_count       = NULL;
}

/**
 * @brief book_data_class_init
 * @param class
 */
static void
book_data_class_init(BookDataClass * class) {
    GObjectClass *gobject_class = G_OBJECT_CLASS(class);

    gobject_class->finalize     = book_data_finalize;
    gobject_class->get_property = book_data_get_property;
    gobject_class->set_property = book_data_set_property;

    properties[PROP_TITLE] = g_param_spec_string("title",
                                                 NULL,
                                                 NULL,
                                                 NULL,
                                                 G_PARAM_READWRITE);

    properties[PROP_AUTHOR] = g_param_spec_string ("author",
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  G_PARAM_READWRITE);

    properties[PROP_GENRE] = g_param_spec_string ("genre",
                                                 NULL,
                                                 NULL,
                                                 NULL,
                                                 G_PARAM_READWRITE);

    properties[PROP_PUBLICATION_DATE] =
        g_param_spec_string("publication_date",
                            NULL,
                            NULL,
                            NULL,
                            G_PARAM_READWRITE);

    properties[PROP_ISBN] = g_param_spec_string ("isbn",
                                                NULL,
                                                NULL,
                                                NULL,
                                                G_PARAM_READWRITE);

    properties[PROP_PRICE] = g_param_spec_string ("price",
                                                 NULL,
                                                 NULL,
                                                 NULL,
                                                 G_PARAM_READWRITE);

    properties[PROP_RATING] = g_param_spec_string ("rating",
                                                  NULL,
                                                  NULL,
                                                  NULL,
                                                  G_PARAM_READWRITE);

    properties[PROP_PUBLISHER] = g_param_spec_string ("publisher",
                                                     NULL,
                                                     NULL,
                                                     NULL,
                                                     G_PARAM_READWRITE);

    properties[PROP_LANGUAGE] = g_param_spec_string ("language",
                                                    NULL,
                                                    NULL,
                                                    NULL,
                                                    G_PARAM_READWRITE);

    properties[PROP_PAGE_COUNT] = g_param_spec_string ("page_count",
                                                      NULL,
                                                      NULL,
                                                      NULL,
                                                      G_PARAM_READWRITE);


    g_object_class_install_properties (gobject_class, N_PROPS, properties);
}

/**
 * @brief book_data_new
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
static
BookData * book_data_new (const char *title,
                          const char *author,
                          const char *genre,
                          const char *publication_date,
                          const char *isbn,
                          const char *price,
                          const char *rating,
                          const char *publisher,
                          const char *language,
                          const char *page_count)
{
    BookData *item = g_object_new(BOOK_TYPE_DATA, NULL);
    item->title   = g_strdup(title);
    item->author  = g_strdup(author);
    item->genre   = g_strdup(genre);
    item->publication_date = g_strdup(publication_date);
    item->isbn    = g_strdup(isbn);
    item->price   = g_strdup(price);
    item->rating  = g_strdup(rating);
    item->publisher = g_strdup(publisher);
    item->language  = g_strdup(language);
    item->page_count = g_strdup(page_count);
    //
    return item;
}

/**
 * @brief create_book_model
 * @return
 */
GListModel *
create_book_model(void) {
    MYSQL *conn = RunInitMySQL();

    conn = LoadMyCNF(conn);

    const char * m_Url ="SELECT "
                        "title, "
                        "author, "
                        "genre, "
                        "publication_date,"
                        "isbn,"
                        "price,"
                        "rating,"
                        "publisher,"
                        "language,"
                        "page_count FROM book_store";

    MYSQL_RES *result = m_RunQuery(conn, m_Url);


    //int num_fields = getNumFields(result);

    MYSQL_ROW row;

    GListStore *store = g_list_store_new(G_TYPE_OBJECT);

    while ((row = getRowData(result))) {
        g_list_store_append(store,
        book_data_new(row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9]));
        printf("\n");
    }

    runCloseConn(conn, result);

    return G_LIST_MODEL(store);
}


/**
 * @brief on_response_remove Response handler
 * to handle OK/Cancel actions
 * @param dialog
 * @param response
 * @param user_data
 */
static void
on_response_remove(GtkAlertDialog *dialog,
                   gint response,
                   gpointer user_data)
{
    GCallback callback = NULL;
    gpointer data = NULL;
    ItemToRemove *mItem = (ItemToRemove *) user_data;

    // Check the response ID and decide which callback to use
    if (response == GTK_RESPONSE_OK) {
        callback = (GCallback) user_data;  // Use the OK callback
        //remove store item
        g_list_store_remove(mItem->store, mItem->selected_index);
        g_print("\nRemoving Selected Index : %d ",mItem->selected_index);
        //on_ok_response(user_data);
    } else if (response == GTK_RESPONSE_CANCEL) {
        callback = (GCallback) user_data;  // Use the Cancel callback
        g_print("\nBack down to removal the selected index : %d ",mItem->selected_index);
    }

    if (callback != NULL) {
        // Call the appropriate callback (OK or Cancel)
        callback = (GCallback) user_data;  // Use the Cancel callback
    }

    g_free(mItem);     // Libera a estrutura se foi g_new/malloc

    // Close the dialog after response
    gtk_window_destroy(GTK_WINDOW(dialog));
}


/**
 * @brief show_alert_dialog Show a Dialog Modal
 * Message to confirmation one action.
 * @param parent_window Window
 * @param message Message
 * @param on_sl_response Callback(Action)
 * to be executed
 * @param ok_data return from button
 * @param mitem Structure with data to
 * be used in action.
 */
static void
show_alert_dialog(GtkWindow *parent_window,
                              const char *message,
                              GCallback on_sl_response,
                              gpointer ok_data,
                              ItemToRemove * mitem) {
    GtkWidget *content_area, *label;

    GtkWidget *dialog = gtk_dialog_new();
    gtk_window_set_title(GTK_WINDOW(dialog), "Message!");

    // Add OK and Cancel buttons explicitly
    gtk_dialog_add_button(GTK_DIALOG(dialog), "OK", GTK_RESPONSE_OK);
    gtk_dialog_add_button(GTK_DIALOG(dialog), "Cancel", GTK_RESPONSE_CANCEL);

    // Get buttons and apply CSS classes
    GtkWidget *ok_btn = gtk_dialog_get_widget_for_response(GTK_DIALOG(dialog),
                                                           GTK_RESPONSE_OK);

    GtkWidget *cancel_btn = gtk_dialog_get_widget_for_response(GTK_DIALOG(dialog),
                                                               GTK_RESPONSE_CANCEL);

    gtk_widget_add_css_class(ok_btn, "confirm-button");
    gtk_widget_add_css_class(cancel_btn, "cancel-button");

    // Load CSS
    GtkCssProvider *provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(provider, "../../data/style.css");
    gtk_style_context_add_provider_for_display(
        gdk_display_get_default(), GTK_STYLE_PROVIDER(provider),
        GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Get the content area of the dialog
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Create a label widget to act as the body of the dialog
    label = gtk_label_new(message);
    gtk_widget_add_css_class(label, "alert-message");
    gtk_box_append(GTK_BOX(content_area), label);

    // Show the dialog
    gtk_widget_show(GTK_WIDGET(dialog));

    g_signal_connect_data(dialog,
                          "response",
                          G_CALLBACK(on_sl_response),
                          mitem,            // Seu user_data
                          NULL, // Função para liberar o user_data
                          0);
}

/**
 * Populate the entry fields.
 * @brief setBookDataToEntry
 * @param m_book_data
 * @param mbbook_data
 */
void setBookDataToEntry(BookData * m_book_data, gpointer mbbook_data){
    BuilderBook * builder_book = mbbook_data;
    //
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_title_obj), m_book_data->title);
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_author_obj), m_book_data->author);
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_genre_obj), m_book_data->genre);
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_publication_date_obj), m_book_data->publication_date);
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_isbn_obj), m_book_data->isbn);
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_price_obj), m_book_data->price);
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_rating_obj), m_book_data->rating);
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_publisher_obj), m_book_data->publisher);
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_language_obj), m_book_data->language);
    gtk_editable_set_text(GTK_EDITABLE(builder_book->m_page_count_obj), m_book_data->page_count);

}

/**
 * Get all data from entry fields and add to model.
 * @brief getEntryToBookData
 * @param mbbook_data
 * @return
 */
BookData * getEntryToBookData(gpointer mbbook_data){
    BuilderBook * m_build_data = mbbook_data;
    BookData *m_book_item = g_object_new(BOOK_TYPE_DATA, NULL);
    //
    m_book_item->title  = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_title_obj)));
    m_book_item->author = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_author_obj)));
    m_book_item->genre = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_genre_obj)));
    m_book_item->publication_date = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_publication_date_obj)));
    m_book_item->isbn = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_isbn_obj)));
    m_book_item->price = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_price_obj)));
    m_book_item->rating = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_rating_obj)));
    m_book_item->publisher = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_publisher_obj)));
    m_book_item->language = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_language_obj)));
    m_book_item->page_count = g_strdup(gtk_editable_get_text(GTK_EDITABLE(m_build_data->m_page_count_obj)));

    //
    return m_book_item;
}


/**
 * @brief Load_Selectade_Item_Action
 * @param button
 * @param mbbook_data
 */
static void
Load_Selectade_Item_Action(GtkButton *button,
                           gpointer mbbook_data)
{
    BuilderBook * build_data = mbbook_data;

    // GtkWidget *window;
    // window = gtk_window_new();

    g_print("\nRun Load Item...!!!");

    GtkSingleSelection *selection_model = GTK_SINGLE_SELECTION(gtk_column_view_get_model(build_data->columnview));

    guint selected_index = gtk_single_selection_get_selected(selection_model);

    if (selected_index != GTK_INVALID_LIST_POSITION)
    {
        BookData *book = gtk_single_selection_get_selected_item(selection_model);

        if (book) {
            //Populate the loaded data from model.
            setBookDataToEntry(book, build_data);

        } else {
            g_print("No valid item found at the selected index.\n");
        }
    } else {
        g_print("No row selected.\n");
    }
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
static void run_additem_callback(GtkButton *button,
                                 gpointer mbbook_data) {
    BuilderBook * m_build_data = mbbook_data;

    g_print("\nRun AddItem CallBack...!!!");

    g_print("\nValue of ColumnView: %p : ", m_build_data->columnview);

    GtkSelectionModel *selection_model = GTK_SELECTION_MODEL(gtk_column_view_get_model(m_build_data->columnview));
    //if (column_view != NULL) g_object_unref(column_view); // Can not unfef ColumnView, erros will happens

   /***
   * Get the Selected Item (for GtkSingleSelection): If using GtkSingleSelection,
   * retrieve the single selected item using gtk_single_selection_get_selected_item().
   **/
    if (GTK_IS_SINGLE_SELECTION(selection_model)) {

        GtkSingleSelection *single_selection = GTK_SINGLE_SELECTION(selection_model);
        //if (selection_model != NULL)  g_object_unref(selection_model); // Selection Model can not unref
        g_print("\nValue is Single Selectionw: %p : ", single_selection);

        // Get the underlying GListModel
        GListModel *list_model = gtk_single_selection_get_model(single_selection);
        //if (single_selection != NULL) g_object_unref(single_selection); // Single Selection can not unref
        g_print("\nValue of store: %p ", list_model);

        // Cast to GListStore
        GListStore *store = G_LIST_STORE(list_model);
        //if (list_model != NULL)g_object_unref(list_model); // List model can not unref, error will happens
        g_print("\nValue of store: %p ", store);

        // Create and append a new item
        // BookData *new_item = book_data_new("Mrs",
        //                                    "Langston Vedenyakin",
        //                                    "Biography",
        //                                    "7/20/1913",
        //                                    "569314541-7",
        //                                    "Rupiah",
        //                                    "4.9",
        //                                    "Dabtype",
        //                                    "Tibetan",
        //                                    "894"); // Replace with your constructor

        BookData * m_bookdata = getEntryToBookData(m_build_data);

        g_list_store_append(store, m_bookdata);
        //if (store != NULL) g_object_unref(store); // store can not unref, error will happens

       // if (m_build_data != NULL) g_object_unref(m_build_data); // Store can not unref, error will happens

        if (m_bookdata != NULL) g_object_unref(m_bookdata); // Store owns a reference now
    } else {
        g_print("\nIs not GtkSingleSelection");
    }

    g_print("\nRun Add Item new...!!!");
}


/**
 * @brief run_remove_item_callback
 * @param button
 * @param column_view
 */
static void
run_remove_item_callback(GtkButton *button,
                                     GtkColumnView *column_view){
    GtkWidget *window;
    window = gtk_window_new();

    g_print("\nRun Remove Item...!!!");

    GtkSingleSelection *selection_model = GTK_SINGLE_SELECTION(gtk_column_view_get_model(column_view));

    if (GTK_IS_SINGLE_SELECTION(selection_model)) {

        GtkSingleSelection *single_selection =
            GTK_SINGLE_SELECTION(selection_model);
        // if (selection_model != NULL)  g_object_unref(selection_model); //
        // Selection Model can not unref
        g_print("\nValue is Single Selectionw: %p : ", single_selection);

        // Get the underlying GListModel
        GListModel *list_model = gtk_single_selection_get_model(single_selection);
        // if (single_selection != NULL) g_object_unref(single_selection); //
        // Single Selection can not unref
        g_print("\nValue of store: %p ", list_model);

        // Cast to GListStore
        GListStore *store = G_LIST_STORE(list_model);
        // if (list_model != NULL)g_object_unref(list_model); // List model can
        // not unref, error will happens
        g_print("\nValue of store: %p ", store);

        guint selected_index = gtk_single_selection_get_selected(selection_model);

        if (selected_index != GTK_INVALID_LIST_POSITION)
        {
            BookData *book = gtk_single_selection_get_selected_item(selection_model);

            if (book) {
                const char *message = "Do you want to remove this item?: ";
                gchar *msg = g_strconcat(message, "Name: ",book->author, NULL);

                g_print("Message: : %s \n", msg);


                //Set item to remove
                ItemToRemove *item_to_remove = g_new(ItemToRemove, 1);
                //
                item_to_remove->store = store;//Set store
                item_to_remove->selected_index = selected_index;//Set selected_idex

                // Create an alert dialog with a simple message and a callback
                show_alert_dialog(GTK_WINDOW(window),
                                  msg,
                                  G_CALLBACK(on_response_remove),
                                  NULL,
                                  item_to_remove);

                g_print("Selected Row Data:\n");
                g_print("  Title: %s\n", book->title);
                g_print("  Author: %s\n", book->author);
                g_print("  Genre: %s\n", book->genre);
                g_print("  Bublication data: %s\n", book->publication_date);
                g_print("  Isbn: %s\n",  book->isbn);
                g_print("  Prince: %s\n", book->price);
                g_print("  Rating: %s\n", book->rating);
                g_print("  Publisher: %s\n", book->publisher);
                g_print("  Language: %s\n", book->language);
                g_print("  Page_count: %s\n", book->page_count);

                // No need to unref selected_person, as get_item returns a "floating" reference
                // or a borrowed reference depending on context, and we're not taking ownership.
            } else {
                g_print("No valid item found at the selected index.\n");
            }
        } else {
            g_print("No row selected.\n");
        }

    }

    g_print("\nEnd Remove Item...!!!");
}



void
activate(GtkApplication *app, gpointer user_data) {

    g_autoptr(GtkBuilder) builder = NULL;

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
    BuilderBook * bbook_data;

    GtkSorter *sorter;
    GActionGroup *actions;
    GAction *action;

    // g_autoptr(GtkBuilder) builder = NULL;
    GtkWindow *window;

    /* Ensure our custom object type is registered with the GObject system
     * before attempting to utilize it through GtkBuilder.
     */
    g_type_ensure (BOOK_TYPE_DATA);

    builder = gtk_builder_new_from_file("../../util/gtkaddtolist.xml");

    /* Connect signal handlers to the constructed widgets. */
    window =  GTK_WINDOW(gtk_builder_get_object (builder, "main_window"));

    g_object_add_weak_pointer(G_OBJECT(window), (gpointer *) & window);

    // //Get columnview from builder
    //GObject *column_view = gtk_builder_get_object(builder, "column_view_frame");

    //Get the whole object that the application needs the builder.
    columnview              = GTK_WIDGET(gtk_builder_get_object(builder, "columnview"));
    GObject *obj_title      = gtk_builder_get_object(builder, "entry_title");
    GObject *obj_author     = gtk_builder_get_object(builder, "entry_author");
    GObject *obj_genre      = gtk_builder_get_object(builder, "entry_genre");
    GObject *obj_public_date= gtk_builder_get_object(builder, "entry_public_date");
    GObject *obj_isbn       = gtk_builder_get_object(builder, "entry_isbn");
    GObject *obj_price      = gtk_builder_get_object(builder, "entry_price");
    GObject *obj_rating     = gtk_builder_get_object(builder, "entry_rating");
    GObject *obj_publisher  = gtk_builder_get_object(builder, "entry_publisher");
    GObject *obj_language   = gtk_builder_get_object(builder, "entry_language");
    GObject *obj_page_count = gtk_builder_get_object(builder, "entry_page_count");

    model = create_book_model();

    selection = GTK_SINGLE_SELECTION(gtk_builder_get_object (builder,
                                                           "single_select_model_id"));

    gtk_single_selection_set_model(selection, G_LIST_MODEL(model));

    bbook_data = g_new(BuilderBook, 1);
    //
    bbook_data->columnview       = GTK_COLUMN_VIEW(columnview);
    //
    bbook_data->m_title_obj      = obj_title;
    bbook_data->m_author_obj     = obj_author;
    bbook_data->m_genre_obj      = obj_genre;
    bbook_data->m_publication_date_obj = obj_public_date;
    bbook_data->m_isbn_obj       = obj_isbn;
    bbook_data->m_price_obj      = obj_price;
    bbook_data->m_rating_obj     = obj_rating;
    bbook_data->m_publisher_obj  = obj_publisher;
    bbook_data->m_language_obj   = obj_language;
    bbook_data->m_page_count_obj = obj_page_count;


    GObject *button_add = gtk_builder_get_object (builder,"button_add");

    g_signal_connect (GTK_BUTTON(button_add),
                             "clicked",
                             G_CALLBACK (run_additem_callback),
                             bbook_data);

    GObject *button_load = gtk_builder_get_object (builder,"button_load");

    g_signal_connect(GTK_BUTTON(button_load),
                     "clicked",
                     G_CALLBACK(Load_Selectade_Item_Action),
                     bbook_data);

    GObject *button_remove = gtk_builder_get_object (builder,"button_remove");

    g_signal_connect(GTK_BUTTON(button_remove),
                     "clicked",
                     G_CALLBACK(run_remove_item_callback),
                     bbook_data->columnview);

    gtk_application_add_window (app, window);
    gtk_window_present(GTK_WINDOW(window));

}//End Activate



