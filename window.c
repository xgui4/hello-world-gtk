#include <gtk/gtk.h>
#include <stdlib.h>
#include "config.h"

static void print_hello(GtkWidget *widget, gpointer data)
{
    g_print("Hello World From GTK!\n");
}

static void go_to_github(GtkButton *button, gpointer user_data) {
    system("xdg-open https://github.com/xgui4/"); 
}

static void send_notification(GtkCheckButton *checkbox, gpointer user_data) {
    gboolean is_active = gtk_check_button_get_active(checkbox);
    if (is_active) {
        system("notify-send -a hellow-world-gtk -i assets/image.jpeg Hello-World-GTK \"Notfication Enable!\""); 
    }
    else {
        system("notify-send -a hellow-world-gtk -i assets/image.jpeg Hello-World-GTK \"Notfication Disabled!\""); 
    }
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *vbox;
    GtkWidget *hello_world_button;
    GtkWidget *logo_image;
    GtkWidget *checkbox1; 
    GtkWidget *go_to_github_button;
    GtkWidget *text_field; 

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), app_name);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_widget_set_margin_top(vbox, 10);
    gtk_widget_set_margin_bottom(vbox, 10);
    gtk_widget_set_margin_start(vbox, 10);
    gtk_widget_set_margin_end(vbox, 10);

    logo_image = gtk_image_new_from_file("assets/image.jpg");

    gtk_widget_set_hexpand(logo_image, TRUE);
    gtk_widget_set_vexpand(logo_image, TRUE);

    gtk_widget_set_halign(logo_image, GTK_ALIGN_FILL);
    gtk_widget_set_valign(logo_image, GTK_ALIGN_FILL);

    gtk_image_set_pixel_size(GTK_IMAGE(logo_image), 500); 

    hello_world_button = gtk_button_new_with_label("Hello World From GTK!");
    gtk_widget_set_halign(hello_world_button, GTK_ALIGN_CENTER);
    g_signal_connect(hello_world_button, "clicked", G_CALLBACK(print_hello), NULL);

    checkbox1 = gtk_check_button_new_with_label("Activate Notification");

    go_to_github_button = gtk_button_new_with_label("Go to my Github"); 

    g_signal_connect(go_to_github_button, "clicked", G_CALLBACK(go_to_github), NULL);

    g_signal_connect(checkbox1, "toggled", G_CALLBACK(send_notification), NULL);

    text_field = gtk_entry_new();

    gtk_box_append(GTK_BOX(vbox), logo_image);
    gtk_box_append(GTK_BOX(vbox), text_field);
    gtk_box_append(GTK_BOX(vbox), hello_world_button);
    gtk_box_append(GTK_BOX(vbox), checkbox1); 
    gtk_box_append(GTK_BOX(vbox), go_to_github_button); 
    gtk_window_present(GTK_WINDOW(window));

    gtk_window_set_child(GTK_WINDOW(window), vbox);
}
