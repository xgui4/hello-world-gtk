#include <gtk/gtk.h>
#include "window_init.h"
#include "config.h"
#include "AppData.h"
#include "window.h"
#include "widgets/GTK_Button.h"
#include "utils.h"
#include "widgets/alert_dialog.h"
#include "myresources.h"
#include "window_callback.h"

void print_hello(GtkWidget *widget, gpointer data)
{
    g_print("Hello World From GTK!\n");

    const char *text = gtk_editable_get_text(GTK_EDITABLE(data));
    const char *buttons[] = {"OK", NULL};

    GtkAlertDialog *popup = gtk_simple_alert_dialog_create("Hello World From GTK!", text, buttons, TRUE); 

    gtk_simple_alert_dialog_show(widget, popup);

    g_object_unref(popup);
}

void go_to_github(GtkButton *button, gpointer app_data) {
    const char* url = repo_link; 
    open_at(url); 
}

void send_notification(GtkCheckButton *checkbox, gpointer app_data) {
    GtkApplication* app = (GtkApplication*)app_data; 
    gboolean is_active = gtk_check_button_get_active(checkbox);
    if (is_active) {
        show_notification(app, app_name, "Notification enable"); 
    }
    else {
        show_notification(app, app_name, "Notification disabled"); 
    }
}

void activate_secret(GtkCheckButton *checkbox, gpointer app_data) {
    Secret *data = (Secret *)app_data;
    gboolean is_active = gtk_check_button_get_active(checkbox);

    if (is_active) {
        if (!data->calendar) { 
            data->calendar = gtk_calendar_new();
            gtk_box_append(GTK_BOX(data->vbox), data->calendar);
        }
    } 
    else {
        if (data->calendar) {
            gtk_box_remove(GTK_BOX(data->vbox), data->calendar);
            data->calendar = NULL; 
        }
    }
}

void save(GtkButton* button, gpointer data) {
    Window_Data *window_data = (Window_Data*)data;
    if (window_data == NULL || window_data->app_data == NULL) {
        g_print("AppData is corrupted, cancelling the save.\n");
        return; 
    }

    AppData *current_app_data = window_data->app_data;
    Secret  *state_copy = window_data->state; 
    GtkWidget *text_field_copy = window_data->text_field;
    GtkWidget *text_field_username_copy = window_data->text_field_username; 

    if (text_field_copy != NULL) {
        const char *const_txt = gtk_editable_get_text(GTK_EDITABLE(text_field_copy)); 
        current_app_data->msg = g_strdup(const_txt); 
    }

    if (state_copy != NULL && state_copy->calendar != NULL) {
        const char *const_txt_birtday = g_date_time_format(gtk_calendar_get_date(GTK_CALENDAR(state_copy->calendar)), "%Y-%m-%d %H:%M:%S"); 
        current_app_data->birthday = g_strdup(const_txt_birtday); 
    }
    
    if (text_field_username_copy != NULL) {
        const char *const_txt_username = gtk_editable_get_text(GTK_EDITABLE(text_field_username_copy)); 
        current_app_data->user_name = g_strdup(const_txt_username);  
    }
    
    JsonNode* root = serialize_app_data(current_app_data); 
    json_node_to_json_file(root, "data.json"); 
    json_node_free(root); 
}
