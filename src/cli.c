#include "cli.h"
#include "utils.h"
#include "cmd_arg.h"
#include "config.h"
#include <gtk/gtk.h>

static void display_result(int cmd_version_argument_used, int cmd_about_argument_used) {
    if (cmd_version_argument_used) {
        g_print("%s App Version %s by %s\n", app_name, version, app_author); 
    }
 
    if (cmd_about_argument_used) {
        g_print(about); 
    }
}

void command_line_interface_display(int argc, char** argv) {
    int cmd_version_argument_used = contains_argument(argc, argv, cmd_args_name[CMD_VERSION]) ||
                                contains_argument(argc, argv, cmd_args_name[CMD_VERSION_LONG]);;
    int cmd_about_argument_used = contains_argument(argc, argv, cmd_args_name[CMD_ABOUT]) || 
                              contains_argument(argc, argv, cmd_args_name[CMD_ABOUT_LONG]);

    if (cmd_version_argument_used == 1 || cmd_about_argument_used == 1) {
        display_result(cmd_version_argument_used, cmd_about_argument_used); 
    }

    else {
        g_print("Unknown Command Line Argument");
    }
}