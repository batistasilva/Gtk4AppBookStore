#ifndef ALERT_HANDLER_H
#define ALERT_HANDLER_H

#include <gtk/gtk.h>
#include <util-app/book-struct-util.h>
#include <dao/bookstore_dao.h>

typedef struct {
    GtkWidget *dialog;
    int *result;
    GMainLoop *loop;
} AlertData;


// void on_alert_accept(GtkButton *btn, gpointer user_data) {
//     AlertData *data = user_data;
//     *data->result = GTK_RESPONSE_ACCEPT;
//     g_main_loop_quit(data->loop);
// }

// void on_alert_reject(GtkButton *btn, gpointer user_data) {
//     AlertData *data = user_data;
//     *data->result = GTK_RESPONSE_REJECT;
//     g_main_loop_quit(data->loop);
// }

static gboolean present_alert_dialog(gpointer user_data) {
    AlertData *data = user_data;
    gtk_window_present(GTK_WINDOW(data->dialog));
    return G_SOURCE_REMOVE;
}

// Callback function for when the "Show Alert" button is clicked
void
on_show_alert_clicked(GtkButton *button,
                      gpointer user_data);


int gtk_alert_ask(const char *message, GtkWindow *parent,
                  const char *option1, const char *option2);

void gtk_alert_show_info(const char *message, GtkWindow *parent);
void gtk_alert_show_warning(const char *message, GtkWindow *parent);
void gtk_alert_show_error(const char *message, GtkWindow *parent);

#endif // ALERT_HANDLER_H
