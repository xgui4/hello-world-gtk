/** @file */

#pragma once

#ifndef APP_DATA_H
#define APP_DATA_H

#include "json-glib-1.0/json-glib/json-glib.h"

/**
 * @struct
 * @brief Contains pointers of App Data 
 */
typedef struct AppData {
    char *user_name; ///< string pointer of username data
    char *msg; /// string pointer of message data
    char *birthday; /// string pointer of birthday data
    char *secret; /// string pointer of secret
} AppData;

extern AppData *app_data; 

/**
 * @brief Create a JsonNode to be used with JSON-Glib library from the AppData Struct
 * @param data The AppData to serialize into a JSON Node
 * @return JsonNode* The JSON Node of the serialized AppData Struct
 */
JsonNode* serialize_app_data(AppData *data); 

#endif