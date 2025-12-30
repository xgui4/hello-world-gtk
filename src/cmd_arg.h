/** @file */

#pragma once

#ifndef CMD_ARGS_H
#define CMD_ARGS_H

/**
 * @brief Command Line Arguments of the programs
 * 
 */
typedef enum CmdArg {
    /*
    "--v"
    */
    CMD_VERSION,
    /*
    * "--version"
    */
    CMD_VERSION_LONG,
    /*
    * "--a"
    */
    CMD_ABOUT,
    /*
    * --about
    */
    CMD_ABOUT_LONG
} CmdArg; 

/**
 * @brief This pointer of a array of string alows to get the value of the CmdArg enum 
 * 
 */
char * cmd_args_name[] = {
    "--v",
    "--version",
    "--a",
    "--about"
};  

#endif