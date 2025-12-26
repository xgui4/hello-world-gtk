#include <gtk/gtk.h>
#include <stdlib.h>
#include "../window.h"
#include "../config.h"
#include "../AppData.h"
#include "../myresources.h"

GtkWidget* gtk_button_init(const char* default_label, GtkAlign align, GCallback callback, gpointer observed_widget) {
    GtkWidget *button = gtk_button_new_with_label(default_label);
    gtk_widget_set_halign(button, align);
    g_signal_connect(button, "clicked", callback, observed_widget);
    return button; 
}