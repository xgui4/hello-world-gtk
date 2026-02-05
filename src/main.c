/** @file The main function of the program */

#include <gtk/gtk.h>
#include "window.h"
#include "config.h"
#include "utils.h"
#include "cli.h"
#include "app_data.h"

int main (int argc, char **argv)
{
  int status = 0;

  if (argc > 1) {
    command_line_interface_display(argc, argv); 
  }

  else {

    char *starting_script = get_string_from_local(language, "starting_script"); 
    
    if (starting_script == NULL) {
      starting_script = "Starting the %s App Version %s by %s\n"; 
    }
    
    g_print(starting_script, app_name, version, app_author);

    AppData *app_data = calloc(1, sizeof *app_data); 

    app_data->user_name = calloc(1 ,sizeof *app_data); 
    app_data->msg = calloc(1, sizeof *app_data); 
    app_data->birthday = calloc(1, sizeof *app_data); 
    app_data->secret = calloc(1, sizeof *app_data); 

    GtkApplication *app = gtk_application_new("dev.xgui4.hello-world-gtk", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), app_data);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    free(app_data->user_name);
    free(app_data->msg); 
    free(app_data->birthday); 
    free(app_data->secret); 
    free(app_data);
  }

  return status;
}