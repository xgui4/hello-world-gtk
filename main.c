#include <gtk/gtk.h>
#include "window.c"
#include "config.h"

int main (int argc, char **argv)
{

  g_print("Starting the %s App Version %s by %s\n", app_name, version, app_author);

  GtkApplication *app;
  int status;

  app = gtk_application_new("dev.xgui4.hello-world-gtk", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run(G_APPLICATION (app), argc, argv);
  g_object_unref(app);

  return status;
}