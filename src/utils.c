#include <stdio.h>
#include "utils.h"
#include <string.h>

/** 
 * Check if the programs was executed with a command line argument
 * Return : true, if argurment is used, else false
*/
int contains_argument(int argc, char *argv[], const char *target) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], target)) {
            return 1; 
        }
    }
    return 0; 
}