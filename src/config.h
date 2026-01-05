/** @file */

#pragma once

#ifndef CONFIG_H
#define CONFIG_H

#include "locale.h"

/**
 * @brief Version of the program
 * 
 */
extern const char * version; 

/**
 * @brief Name of the App
 * 
 */
extern const char * app_name; 

/**
 * @brief Author of the App
 * 
 */
extern const char * app_author; 

/**
 * @brief Information about the App
 * 
 */
extern const char * about; 

/**
 * @brief Link of the repo to go with the button to the repo
 * 
 */
extern const char * repo_link; 

/**
 * @brief Default Language for the App
 * 
 */
extern const Locale language; 

/**
 * @brief Path for the App Image
 * 
 */
extern const char* app_image_path; 

#endif // CONFIG_H