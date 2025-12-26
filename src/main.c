#include <gtk/gtk.h>
#include "window.h"
#include "config.h"
#include "utils.h"
#include "cli.h"
#include "AppData.h"

int main (int argc, char **argv)
{
  int status = 0;

  if (argc > 1) {
    command_line_interface_display(argc, argv); 
  }

  else {
    g_print("Starting the %s App Version %s by %s\n", app_name, version, app_author);

    AppData *app_data = malloc(sizeof *app_data); 

    app_data->user_name = malloc(sizeof *app_data); 
    app_data->msg = malloc(sizeof *app_data); 
    app_data->birthday = malloc(sizeof *app_data); 
    app_data->secret = malloc(sizeof *app_data); 

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