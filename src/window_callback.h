/** @file  */

#pragma once

#ifndef WINDOW_CALLBACK_H
#define WINDOW_CALLBACK_H

#include <gtk/gtk.h>
#include "AppData.h"
#include "utils.h"
#include "widgets/alert_dialog.h"
#include "myresources.h"

extern void print_hello(GtkWidget *widget, gpointer data); 

extern void go_to_github(GtkButton *button, gpointer app_data); 

extern void send_notification(GtkCheckButton *checkbox, gpointer app_data); 

extern void activate_secret(GtkCheckButton *checkbox, gpointer app_data);

extern void save(GtkButton* button, gpointer data); 

#endif