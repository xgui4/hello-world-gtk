/** @file */

#pragma once

#ifndef ALERT_DIALOG_H
#define ALERT_DIALOG_H

#include <gtk/gtk.h>

/**
 * @brief Create a GTK Alert Dialog and initiate it by returning it as a pointer of GtAlertDialog
 * @param title title of the alert dialog 
 * @param body body of the Alert Dialog
 * @param buttons Array of buttons
 * @param is_modal Made the GTK Alert a modal or not
 * @return GtkAlertDialog* The button created by the function
 */
GtkAlertDialog* gtk_simple_alert_dialog_create(const char* title, const char* body, const char* buttons[], gboolean is_modal); 

/**
 * @brief show the dialog and report failure with a gboolean
 * @param widget The parent widget that own the Alert Dialog
 * @param popup The GtkAlertDialog dialog
 * @return gboolean, TRUE if success, FALSE if otherwise
 */
gboolean gtk_simple_alert_dialog_show(GtkWidget* widget, GtkAlertDialog* popup); 

#endif