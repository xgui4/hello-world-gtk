#include <stdio.h>
#include "utils.h"
#include <gtk/gtk.h>
#include <string.h>
#include "config.h"
#include "json-glib-1.0/json-glib/json-glib.h"

gboolean contains_argument(int argc, char *argv[], const char *target) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], target)) {
            return 1; 
        }
    }
    return 0; 
}

void json_node_to_json_file(JsonNode* root, const char* filename) {
    JsonGenerator *gen = json_generator_new();
    json_generator_set_root(gen, root);
    json_generator_set_pretty(gen, TRUE);

    GError *error = NULL;
    if (!json_generator_to_file(gen, filename, &error)) {
        g_printerr("Error saving file: %s\n", error->message);
        g_error_free(error);
    }

    // Clean up
    g_object_unref(gen);
}

gboolean open_at(const char *path)
{
    #if defined __APPLE__
    gprint("Unsupported OS detected");
    return FALSE;
    #endif

    GError *error = NULL;
    gboolean success;

    success = g_app_info_launch_default_for_uri(path, NULL, &error);

    if (!success) {
        g_printerr("Failed to open location: %s\n", error->message);
        g_error_free(error);
        return FALSE;
    }

    return TRUE;
}

gboolean open_locally_at(const char *path)
{
    gboolean success = TRUE; 

    char *uri = g_filename_to_uri(path, NULL, NULL);
    success = open_at(uri);
    g_free(uri);

    return success; 
}

void show_notification_with_custom_icon(GtkApplication *app, GIcon *icon, const char *title, const char *body) {
    GNotification *notification = g_notification_new(title);
    g_notification_set_body(notification, body);

    g_notification_set_icon(notification, icon);

    g_application_send_notification(G_APPLICATION(app), app_name, notification);

    g_object_unref(notification);
    g_object_unref(icon);
}

void show_notification(GtkApplication *app, const char *title, const char *body) {
    GNotification *notification = g_notification_new(title);
    g_notification_set_body(notification, body);

    GIcon *icon = g_themed_icon_new("xorg");
    g_notification_set_icon(notification, icon);

    g_application_send_notification(G_APPLICATION(app), app_name, notification);

    g_object_unref(notification);
    g_object_unref(icon);
}
