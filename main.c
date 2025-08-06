#include <bookstore.h>

int main(int argc, char **argv) {
    g_autoptr(GtkApplication) app = NULL;
    int status;

#ifdef GTK_SRCDIR
    g_chdir (GTK_SRCDIR);
#endif
    G_GNUC_BEGIN_IGNORE_DEPRECATIONS
    app = gtk_application_new ("com.br.bookstore", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);

    return status;
}
