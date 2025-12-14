#include <gtk/gtk.h>
#include <stdlib.h>
#include "config.h"

static void print_hello(GtkWidget *widget, gpointer data)
{
    g_print("Hello World From GTK!\n");
}

static void go_to_github() {
    system("xdg-open https://github.com/xgui4/"); 
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *button;
    GtkWidget *image;
    GtkWidget *checkbox1; 
    GtkWidget *button2; 

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), app_name);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(vbox, 10);
    gtk_widget_set_margin_bottom(vbox, 10);
    gtk_widget_set_margin_start(vbox, 10);
    gtk_widget_set_margin_end(vbox, 10);

    image = gtk_image_new_from_file("assets/image.jpg");

    gtk_widget_set_hexpand(image, TRUE);
    gtk_widget_set_vexpand(image, TRUE);

    gtk_widget_set_halign(image, GTK_ALIGN_FILL);
    gtk_widget_set_valign(image, GTK_ALIGN_FILL);

    gtk_image_set_pixel_size(GTK_IMAGE(image), 500); 

    button = gtk_button_new_with_label("Hello World From GTK!");
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
    g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);

    checkbox1 = gtk_check_button_new(); 

    button2 = gtk_button_new_with_label("Go to my Github"); 

    g_signal_connect(button2, "clicked", G_CALLBACK(go_to_github), NULL);


    gtk_box_append(GTK_BOX(vbox), image);
    gtk_box_append(GTK_BOX(vbox), button);
    gtk_box_append(GTK_BOX(vbox), checkbox1); 
    gtk_box_append(GTK_BOX(vbox), button2); 

    gtk_window_set_child(GTK_WINDOW(window), vbox);
    gtk_window_present(GTK_WINDOW(window));
}
