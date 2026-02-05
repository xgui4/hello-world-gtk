#include <gtk/gtk.h>
#include <stdlib.h>
#include <json-glib-1.0/json-glib/json-glib.h>
#include "window_init.h"
#include "window.h"
#include "config.h"
#include "app_data.h"
#include "window.h"
#include "widgets/button.h"
#include "utils.h"
#include "widgets/alert_dialog.h"
#include "myresources.h" 
#include "window_callback.h"

extern void popup_hello_world_button(GtkWidget *widget, gpointer data); 

extern void go_to_github(GtkButton *button, gpointer app_data); 

extern void send_notification(GtkCheckButton *checkbox, gpointer app_data); 

extern void activate_secret(GtkCheckButton *checkbox, gpointer app_data);

extern void save(GtkButton* button, gpointer data); 

GtkWidget* window_init(GtkApplication* app, int width, int height) {
    GtkWidget* window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), app_name);
    gtk_window_set_default_size(GTK_WINDOW(window), width, height);
    return window; 
}

GtkWidget* vbox_init(int spacing, GtkOrientation orientation, int margin_top, int margin_bottom, int margin_start, int margin_end) {
    GtkWidget* vbox = gtk_box_new(orientation, spacing);
    gtk_widget_set_margin_top(vbox, margin_top);
    gtk_widget_set_margin_bottom(vbox, margin_bottom);
    gtk_widget_set_margin_start(vbox, margin_start);
    gtk_widget_set_margin_end(vbox, margin_end);
    return vbox; 
}

GtkWidget* logo_picture_init(const char* resource_path, gboolean hexpand, gboolean vexpand, GtkAlign align, gboolean can_shrink, GtkContentFit gtk_content_fit) {
    GtkWidget *picture = gtk_picture_new_for_resource(resource_path);
    gtk_widget_set_hexpand(picture, hexpand);
    gtk_widget_set_vexpand(picture, vexpand);
    gtk_widget_set_halign(picture, align);
    gtk_widget_set_valign(picture, align);
    gtk_picture_set_can_shrink(GTK_PICTURE(picture), can_shrink);
    gtk_picture_set_content_fit(GTK_PICTURE(picture), gtk_content_fit);
    return picture;
}

GtkWidget* text_field_init() {
    GtkWidget *text_field = gtk_entry_new();
    return text_field; 
}

GtkWidget* save_button_init(const char* label, GtkAlign align, Window_Data *data) {
    GtkWidget *save_button = button_init(label, align, G_CALLBACK(save), data); 
    return save_button; 
}

GtkWidget* hello_world_button_init(const char* default_label, GtkAlign align, GtkWidget* text_field) {
    GtkWidget *hello_world_button = gtk_button_new_with_label(default_label);
    gtk_widget_set_halign(hello_world_button, align);
    g_signal_connect(hello_world_button, "clicked", G_CALLBACK(popup_hello_world_button), text_field);
    return hello_world_button; 
}

GtkWidget* go_to_my_github_init(const char* default_label, GtkAlign align, GtkWidget* text_field) {
    GtkWidget *go_to_github_button = gtk_button_new_with_label(default_label); 
    gtk_widget_set_halign(go_to_github_button, align);
    g_signal_connect(go_to_github_button, "clicked", G_CALLBACK(go_to_github), text_field);
    return go_to_github_button; 
}

GtkWidget* checkbox1_init(const char* default_label, GtkApplication* app) {
    GtkWidget *checkbox1 = gtk_check_button_new_with_label(default_label);
    g_signal_connect(checkbox1, "toggled", G_CALLBACK(send_notification), app);
    return checkbox1; 
}

Secret* state_init(GtkWidget* vbox) {
    Secret *state = g_malloc(sizeof(Secret));
    state->vbox = vbox;
    state->secret_entry = NULL; 
    return state; 
}

Window_Data* window_data_init(Secret* state, GtkWidget* text_field, GtkWidget* text_field_user_name, GtkWidget* calendar, GtkWidget* secret_entry,  AppData* user_data) {
    Window_Data *data = g_malloc(sizeof(Window_Data));
    data->state = state;
    data->text_field = text_field;
    data->text_field_username = text_field_user_name;
    data->calendar = calendar;
    data->secret_entry = secret_entry;
    data->app_data = user_data;
    return data;
}

GtkWidget* checkbox2_init(const char* default_label, Secret* state) {
    GtkWidget *checkbox2 = gtk_check_button_new_with_label(default_label);
    g_signal_connect(checkbox2, "toggled", G_CALLBACK(activate_secret), state);
    return checkbox2; 
}

GtkWidget* calendar_init() {
    GtkWidget *calendar = gtk_calendar_new();
    return calendar; 
}

GtkWidget *secret_input_init(const char *label)
{
    GtkWidget *text_field = gtk_entry_new(); 

    gtk_entry_set_placeholder_text(GTK_ENTRY(text_field), label); 

    return text_field; 
}
