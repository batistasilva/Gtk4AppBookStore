#include <gtk/gtk.h>
#include <alert_handler.h>
#include <src/bookstore.h>

/**
 * @brief quit_activated
 * @param action
 * @param parameter
 * @param application
 */
void
quit_activated(GSimpleAction *action, GVariant *parameter, GApplication *application) {
    g_application_quit (application);
}

/**
 * @brief book_mng_action
 * @param action
 * @param app
 * @param param
 */
void book_mng_action(GSimpleAction *action, GtkApplication *app, gpointer param){
  GtkWindow * win = param;
  //
  book_mng_activate(app, win);
}


/**
 * @brief new_window_activated
 * @param action
 * @param parameter
 * @param application
 */
void
new_window_activated(GSimpleAction *action, GVariant *parameter, GApplication *application) {
    GtkApplication *app = GTK_APPLICATION(application);
    GtkWidget *new_win = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(new_win), "New Top-Level Window (Modal)");
    gtk_window_set_default_size(GTK_WINDOW(new_win), 300, 200);

    // Set the new window to be transient for the main application window
    // This tells the window manager that new_win belongs to the main window.
    // We need to get the active window from the application to set it as the transient parent.
    GtkWidget *main_window = (GtkWidget *)gtk_application_get_active_window(app); // Explicit cast added here
    if (main_window) {
        gtk_window_set_transient_for(GTK_WINDOW(new_win), GTK_WINDOW(main_window));
    }

    // Set the new window to be modal
    // This prevents interaction with the parent window until new_win is closed.
    gtk_window_set_modal(GTK_WINDOW(new_win), TRUE);

    // Add a label to the new window for demonstration
    GtkWidget *label = gtk_label_new("This is a new top-level modal window!");
    gtk_window_set_child(GTK_WINDOW(new_win), label);

    gtk_window_present(GTK_WINDOW(new_win));
    g_print("New top-level modal window opened!\n");
}

/**
 * @brief app_startup
 * @param application
 * @param win
 */
void
app_startup (GApplication *application, GtkWidget *win)
{
    GtkApplication *app = GTK_APPLICATION (application);

    GSimpleAction *act_quit = g_simple_action_new ("quit", NULL);
    GSimpleAction *act_book_mng = g_simple_action_new("book-mng", NULL); //Action Book Manager

    g_action_map_add_action (G_ACTION_MAP (app), G_ACTION (act_quit));
    g_action_map_add_action (G_ACTION_MAP (app), G_ACTION (act_book_mng)); // Add new window action


    // CORRECTED: Connect act_file to file_activated and pass 'application' as user_data
    g_signal_connect (act_quit, "activate", G_CALLBACK (quit_activated), application);
    g_signal_connect (act_book_mng, "activate", G_CALLBACK (book_mng_action), win); // Connect new window action

    GMenu *menubar = g_menu_new ();

    GMenuItem *menu_item_menu = g_menu_item_new ("Menu", NULL);

    GMenu *menu = g_menu_new ();

    GMenuItem *menu_item_quit = g_menu_item_new ("Quit", "app.quit");
    GMenuItem *menu_item_book_mng = g_menu_item_new("Manager Books","app.book-mng");

    g_menu_append_item (menu, menu_item_book_mng);
    g_menu_append_item (menu, menu_item_quit);

    g_object_unref (menu_item_book_mng);
    g_object_unref (menu_item_quit);

    g_menu_item_set_submenu (menu_item_menu, G_MENU_MODEL (menu));

    g_object_unref (menu);

    g_menu_append_item (menubar, menu_item_menu);

    g_object_unref (menu_item_menu);

    gtk_application_set_menubar (GTK_APPLICATION (app), G_MENU_MODEL (menubar));
}


void
app_activate (GApplication *application)
{
    GtkApplication *app = GTK_APPLICATION (application);

    GtkWidget *win = gtk_application_window_new (app);

    gtk_window_set_title (GTK_WINDOW (win), "[ BookStoreApp ]");

    gtk_window_set_default_size (GTK_WINDOW (win), 1024,680);

    // Load image from file using GFile
    GFile *file = g_file_new_for_path("../gui/images/bookstore-mng.png");
    GdkTexture *texture = gdk_texture_new_from_file(file, NULL);
    g_object_unref(file); // Cleanup GFile

    // Create a GtkPicture with the texture
    GtkWidget *picture = gtk_picture_new_for_paintable(GDK_PAINTABLE(texture));
    gtk_picture_set_can_shrink(GTK_PICTURE(picture), TRUE);
    gtk_picture_set_keep_aspect_ratio(GTK_PICTURE(picture), FALSE); // Stretch to fill

    gtk_picture_set_can_shrink(GTK_PICTURE(picture), TRUE);
    gtk_widget_set_hexpand(picture, TRUE);
    gtk_widget_set_vexpand(picture, TRUE);
    gtk_widget_set_valign(picture, GTK_ALIGN_FILL);
    gtk_widget_set_halign(picture, GTK_ALIGN_FILL);
    gtk_widget_set_size_request(picture, 1024, 700);

    // Place the picture inside an overlay, so you can add content above it
    GtkWidget *overlay = gtk_overlay_new();
    gtk_overlay_set_child(GTK_OVERLAY(overlay), picture);

    gtk_window_set_child(GTK_WINDOW(win), overlay);

    gtk_application_window_set_show_menubar (GTK_APPLICATION_WINDOW (win), TRUE);

    //Enable the menu
    app_startup(application, win);

    gtk_window_present (GTK_WINDOW (win));
}



#define APPLICATION_ID "com.br.bookstore"

