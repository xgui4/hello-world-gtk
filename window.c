#include <gtk/gtk.h>
#include "config.h"
#include "window.h"

void print_hello(GtkWidget *widget, gpointer   data)
{
  g_print("Hello World From GTK!\n");
}

void activate(GtkApplication *app, gpointer user_data)
{

  GtkBox *box;
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *image; 

  char * app_window_name = app_name; 

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), app_window_name);
  gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

  button = gtk_button_new_with_label("Hello World From GTK!");
  image = gtk_image_new_from_file("assets/image.jpg");
  gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
  gtk_widget_set_valign(button, GTK_ALIGN_CENTER);
  g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
  gtk_window_set_child(GTK_WINDOW(window), button);
  gtk_window_set_child(GTK_WINDOW(window), image); 

  gtk_window_present(GTK_WINDOW(window));
} 