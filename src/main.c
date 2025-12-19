#include <gtk/gtk.h>
#include "window.h"
#include "config.h"
#include "utils.h"
#include "cli.h"

int main (int argc, char **argv)
{
  int status = 0;

  if (argc > 1) {
    command_line_interface_display(argc, argv); 
  }

  else {
    g_print("Starting the %s App Version %s by %s\n", app_name, version, app_author);

    GtkApplication *app;

    app = gtk_application_new("dev.xgui4.hello-world-gtk", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
  }

  return status;
}