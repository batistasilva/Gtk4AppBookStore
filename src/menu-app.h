#ifndef MENU_APP_H
#define MENU_APP_H
#include <gtk/gtk.h>

void book_mng_action(GSimpleAction *action, gpointer param, GtkApplication *app, GtkWindow * win);

void
file_activated(GSimpleAction *action, GVariant *parameter, GApplication *application);

void
quit_activated(GSimpleAction *action, GVariant *parameter, GApplication *application);

void
new_window_activated(GSimpleAction *action, GVariant *parameter, GApplication *application);

void
app_activate (GApplication *application);

void
app_startup (GApplication *application, GtkWidget *win);

#endif // MENU_APP_H
