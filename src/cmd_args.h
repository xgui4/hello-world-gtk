/*
 * Command Line Arguments of the programs
 */
enum cmd_args {
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
    CMD_ABOUT_LONG,
    /*
    * The number of command line arguments
    */
    CMD_COUNT
}; 

/*
* This array of string alows to get the value of the cmd_args enum 
*/
char * cmd_args_name[] = {
    "--v",
    "--version",
    "--a",
    "--about"
};  