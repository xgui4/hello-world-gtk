#pragma once
#ifndef UTILS_H
#define UTILS_H
#include "json-glib-1.0/json-glib/json-glib.h"

/** 
 * @brief Check if the programs was executed with a command line argument
 * @param argc Integer that represent the numbers of cmd args
 * @param argv Array of char* of characters
 * @param *target Pointer of the String of the argument to check
 * @return TRUE (int 1), if argument is used, else FALSE (int 0)
*/
int contains_argument(int argc, char *argv[], const char *target); 

/**
 * @brief Print to a file named with the filename parameters
 * @param root JsonNode to print to a json file
 * @param filename Filename of the json file to print
 */
void json_node_to_json_file(JsonNode* root, const char* filename); 

#endif