/** @file */

#pragma once
#ifndef LOCALE_H
#define LOCALE_H

/**
 * @brief Represent the list of supported language
 * @enum
 */
typedef enum Locale {
    LOCALE_FR, ///> French (fr.json)
    LOCALE_EN, ///> English (en.json)
    LOCALE_COUNT ///> Total number of supported languages
} Locale; 


/**
 * @brief Filename and relative path location of the Locale File
 * 
 */
extern char * locale_filename[]; 

#endif // LOCALE_H