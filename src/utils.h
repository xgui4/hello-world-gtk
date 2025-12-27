#pragma once
#ifndef UTILS_H
#define UTILS_H
#include <gtk/gtk.h>
#include "json-glib-1.0/json-glib/json-glib.h"

/** 
 * @brief Check if the programs was executed with a command line argument
 * @param argc Integer that represent the numbers of cmd args
 * @param argv Array of char* of characters
 * @param *target Pointer of the String of the argument to check
 * @return TRUE, if argument is used, else FALSE
*/
gboolean contains_argument(int argc, char *argv[], const char *target); 

/**
 * @brief Print to a file named with the filename parameters
 * @param root JsonNode to print to a json file
 * @param filename Filename of the json file to print
 */
void json_node_to_json_file(JsonNode* root, const char* filename); 

/**
 * @brief Open the file or site via the correct method depending of the OS
 * @param path the string of the path to go to
 * @return TRUE if success, else FALSE
 */
gboolean open_at(const char* path); 

/**
 * @brief Open the file or site via the correct method depending of the OS but with automatic uri translation
 * @param path the string of the path to go to
 * @return TRUE if success, else FALSE
 */
gboolean open_at(const char* path); 

/**
 * @brief Show a notification using GNotification with a custom icon
 * @param app* the pointer to the app itself
 * @param icon* the custom icon pointer
 * @param title* the string pointer of the notification title
 * @param body* the string pointer of the notification body 
 */
void show_notification_with_custom_icon(GtkApplication *app, GIcon *icon, const char *title, const char *body); 

/**
 * @brief Show a notification using GNotification 
 * @param app* the pointer to the app itself
 * @param title* the string pointer of the notification title
 * @param body* the string pointer of the notification body 
 */
void show_notification(GtkApplication *app, const char *title, const char *body); 

#endif