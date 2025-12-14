#include <gtk/gtk.h>
#include "config.h"

static void print_hello(GtkWidget *widget, gpointer data)
{
    g_print("Hello World From GTK!\n");
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *image;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), app_name);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(vbox, 10);
    gtk_widget_set_margin_bottom(vbox, 10);
    gtk_widget_set_margin_start(vbox, 10);
    gtk_widget_set_margin_end(vbox, 10);

    image = gtk_image_new_from_file("assets/image.jpg");

    button = gtk_button_new_with_label("Hello World From GTK!");
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

    gtk_box_append(GTK_BOX(vbox), image);
    gtk_box_append(GTK_BOX(vbox), button);

    gtk_window_set_child(GTK_WINDOW(window), vbox);
    gtk_window_present(GTK_WINDOW(window));
}
