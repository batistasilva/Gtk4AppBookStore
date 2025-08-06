#include "alert_handler.h"
#include <gtk/gtk.h>


/**
 * @brief on_alert_accept
 * @param btn
 * @param user_data
 */
void on_alert_accept(GtkButton *btn, gpointer user_data)
{
  gpointer *data = (gpointer *)user_data;
  int *result = (int *)data[0];
  GMainLoop *loop = (GMainLoop *)data[1];

  *result = GTK_RESPONSE_ACCEPT;
  g_main_loop_quit(loop);
}

/**
 * @brief on_alert_reject
 * @param btn
 * @param user_data
 */
void on_alert_reject(GtkButton *btn, gpointer user_data)
{
  gpointer *data = (gpointer *)user_data;
  int *result = (int *)data[0];
  GMainLoop *loop = (GMainLoop *)data[1];

  *result = GTK_RESPONSE_REJECT;
  g_main_loop_quit(loop);
}

/**
 * @brief gtk_alert_ask
 * @param message
 * @param parent
 * @param option1
 * @param option2
 * @return
 */
int
gtk_alert_ask(const char *message,
                GtkWindow *parent,
              const char *option1,
              const char *option2)
{
  GtkWidget *dialog = gtk_dialog_new();
  //
  gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
  gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
  gtk_window_set_title(GTK_WINDOW(dialog), "Please Confirm");
  gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
  gtk_window_set_default_size(GTK_WINDOW(dialog), 360, -1);
  gtk_widget_add_css_class(dialog, "alert-dialog");

  GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
  gtk_widget_set_margin_top(content_area, 20);
  gtk_widget_set_margin_bottom(content_area, 20);
  gtk_widget_set_margin_start(content_area, 20);
  gtk_widget_set_margin_end(content_area, 20);

  GtkWidget *label = gtk_label_new(message);
  gtk_label_set_wrap(GTK_LABEL(label), TRUE);
  gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
  gtk_widget_set_halign(label, GTK_ALIGN_CENTER);
  gtk_widget_set_margin_bottom(label, 15);
  gtk_box_append(GTK_BOX(content_area), label);

  GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
  gtk_widget_set_halign(button_box, GTK_ALIGN_CENTER);

  GtkWidget *btn1 = gtk_button_new_with_label(option1);
  GtkWidget *btn2 = gtk_button_new_with_label(option2);
  gtk_box_append(GTK_BOX(button_box), btn1);
  gtk_box_append(GTK_BOX(button_box), btn2);
  gtk_box_append(GTK_BOX(content_area), button_box);

  int result = -1;
  GMainLoop *loop = g_main_loop_new(NULL, FALSE);
  gpointer userdata[2] = {&result, loop};

  g_signal_connect(btn1, "clicked", G_CALLBACK(on_alert_accept), userdata);
  g_signal_connect(btn2, "clicked", G_CALLBACK(on_alert_reject), userdata);

  gtk_window_present(GTK_WINDOW(dialog));// ← this will center it;
  g_main_loop_run(loop);

  gtk_window_destroy(GTK_WINDOW(dialog));
  g_main_loop_unref(loop);

  return result;
}

/**
 * @brief gtk_alert_show_internal
 * @param title
 * @param message
 * @param parent
 * @param style_class
 * @param icon_name
 **/
static void gtk_alert_show_internal(
            const char *title,
            const char *message,
            GtkWindow *parent,
            const char *style_class,
            const char *icon_name
) {
    GtkWidget *dialog = gtk_dialog_new();
    //
    gtk_window_set_transient_for(GTK_WINDOW(dialog), parent);
    gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
    gtk_window_set_title(GTK_WINDOW(dialog), title);
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
    gtk_window_set_default_size(GTK_WINDOW(dialog), 360, -1);

    gtk_widget_add_css_class(dialog, "alert-dialog");
    if (style_class)
        gtk_widget_add_css_class(dialog, style_class);

    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_widget_set_margin_top(content_area, 20);
    gtk_widget_set_margin_bottom(content_area, 20);
    gtk_widget_set_margin_start(content_area, 20);
    gtk_widget_set_margin_end(content_area, 20);

    // HBox to hold icon + message
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_widget_set_halign(hbox, GTK_ALIGN_CENTER);

    // Icon
    GtkWidget *image = gtk_image_new_from_icon_name(icon_name);
    gtk_widget_set_size_request(image, 32, 32);
    gtk_box_append(GTK_BOX(hbox), image);

    // Message
    GtkWidget *label = gtk_label_new(message);
    gtk_label_set_wrap(GTK_LABEL(label), TRUE);
    gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_LEFT);
    gtk_widget_set_valign(label, GTK_ALIGN_CENTER);
    gtk_box_append(GTK_BOX(hbox), label);

    // Button
    GtkWidget *button = gtk_button_new_with_label("OK");
    gtk_widget_add_css_class(button, "suggested-action");
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_window_destroy), dialog);

    // Add to content area
    gtk_box_append(GTK_BOX(content_area), hbox);
    gtk_box_append(GTK_BOX(content_area), button);

    gtk_window_present(GTK_WINDOW(dialog));
}

/**
 * @brief gtk_alert_show_info
 * @param message
 * @param parent
 **/
void gtk_alert_show_info(
    const char *message,
    GtkWindow *parent
) {
    gtk_alert_show_internal("Info",
                            message,
                            parent,
                            "info-alert",
                            "dialog-information");
}

/**
 * @brief gtk_alert_show_warning
 * @param message
 * @param parent
 **/
void gtk_alert_show_warning(
     const char *message,
     GtkWindow *parent
) {
    gtk_alert_show_internal("Warning",
                            message,
                            parent,
                            "warning-alert",
                            "dialog-warning");
}

/**
 * @brief gtk_alert_show_error
 * @param message
 * @param parent
 **/
void gtk_alert_show_error(
    const char *message,
    GtkWindow *parent
) {
    gtk_alert_show_internal("Error",
                            message,
                            parent,
                            "error-alert",
                            "dialog-error");
}


