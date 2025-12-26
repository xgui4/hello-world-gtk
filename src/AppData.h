#pragma once
#ifndef APPDATA_H
#define APPDATA_H
#include "AppData.h"
#include "json-glib-1.0/json-glib/json-glib.h"

typedef struct AppData {
    char *user_name;
    char *msg; 
    char *birthday; 
    char *secret; 
} AppData;

extern AppData *app_data; 

/**
 * @brief Create a JsonNode to be used with JSON-Glib library from the AppData Struct
 * @param data The AppData to serialize into a JSON Node
 * @return JsonNode* The JSON Node of the serialized AppData Struct
 */
JsonNode* serialize_app_data(AppData *data); 

#endif