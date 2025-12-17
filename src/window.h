#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer  data); 

static void go_to_github(GtkButton *button, gpointer user_data); 

static void send_notifcation(GtkCheckButton *checkbox, gpointer user_data); 

static void activate(GtkApplication *app, gpointer user_data);