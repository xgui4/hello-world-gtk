/** @file */

#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <gtk/gtk.h>

/**
 * @brief Create a GTK Button and initiate it by giving it as a GtkWidget<
 * @param default_label Default Label of the button 
 * @param align Align (GtkAlign) of the button 
 * @param callback Callback (like a lamda function) of the button, can be NULL
 * @param observed_widget gpointer of a GtkWidget for the function callback, can be NULL
 * @return GtkWidget* The button created by the functionn
 */
GtkWidget* button_init(const char* default_label, GtkAlign align, GCallback callback, gpointer observed_widget); 

#endif