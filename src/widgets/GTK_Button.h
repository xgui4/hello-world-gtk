#pragma once

#ifndef GTK_BUTTON_H
#define GTK_BUTTON_H

#include <gtk/gtk.h>

GtkWidget* gtk_button_init(const char* default_label, GtkAlign align, GCallback callback, gpointer observed_widget); 

#endif