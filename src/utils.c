#include <stdio.h>
#include <string.h> // Required for strcmp()
#include "utils.h"


/** 
 * 
*/
int contains_argument(int argc, char *argv[], const char *target) {
    // Start loop from index 1 to skip the program name itself (argv[0])
    for (int i = 1; i < argc; i++) {
        // Use strcmp() to compare the current argument (argv[i]) with the target string
        if (strcmp(argv[i], target) == 0) {
            // Found a match
            return 1; // Return true
        }
    }
    // Loop finished, no match found
    return 0; // Return false
}