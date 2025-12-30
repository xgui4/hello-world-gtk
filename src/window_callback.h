/** @file  */

#pragma once

#ifndef WINDOW_CALLBACK_H
#define WINDOW_CALLBACK_H

#include <gtk/gtk.h>
#include "AppData.h"
#include "utils.h"
#include "widgets/alert_dialog.h"
#include "myresources.h"

/**
 * @brief Callback Function : Show a hello world popup from the hello world button 
 * 
 * @param widget the widget pointer needed as a boilerplate (can be NULL)
 * @param data the dte gpointer needed to create the popup
 */
extern void popup_hello_world_button(GtkWidget *widget, gpointer data); 

/**
 * @brief Callback Function : Go to the GitHub project website from the go_to_github_button  
 * 
 * @param button 
 * @param app_data 
 */
extern void go_to_github(GtkButton *button, gpointer app_data); 


/**
 * @brief 
 * 
 * @param checkbox 
 * @param app_data 
 */
extern void send_notification(GtkCheckButton *checkbox, gpointer app_data); 

/**
 * @brief 
 * 
 * @param checkbox 
 * @param app_data 
 */
extern void activate_secret(GtkCheckButton *checkbox, gpointer app_data);


/**
 * @brief 
 * 
 * @param button 
 * @param data 
 */
extern void save(GtkButton* button, gpointer data); 

#endif