#include <gtk/gtk.h>
#include "window.c"
#include "config.h"
#include "utils.h"
#include "cmd_args.c"

int main (int argc, char **argv)
{
  int status = 0;

  if (contains_argument(argc, argv, cmd_args_name[CMD_VERSION]) || contains_argument(argc, argv, cmd_args_name[CMD_VERSION_LONG])) {
    g_print("%s App Version %s by %s\n", app_name, version, app_author); 
  }

  if (contains_argument(argc, argv, cmd_args_name[CMD_ABOUT]) || contains_argument(argc, argv, cmd_args_name[CMD_ABOUT_LONG])) {
    g_print(about); 
  }

  else {
    g_print("Starting the %s App Version %s by %s\n", app_name, version, app_author);

    GtkApplication *app;

    app = gtk_application_new("dev.xgui4.hello-world-gtk", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);

    status = g_application_run(G_APPLICATION (app), argc, argv);
    g_object_unref(app);
  }

  return status;
}