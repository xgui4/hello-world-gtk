#pragma once
#ifndef WINDOW_INIT_H
#define WINDOW_INIT_H
#include <gtk/gtk.h>
#include "AppData.h"
#include "utils.h"
#include "widgets/alert_dialog.h"
#include "myresources.h"

typedef struct Secret {
    GtkWidget *vbox; 
    GtkWidget *calendar; 
    GtkWidget *secret_entry;
} Secret; 

typedef struct Window_Data {
    Secret* state; 
    GtkWidget* text_field; 
    GtkWidget* text_field_username;
    AppData* app_data; 
} Window_Data; 


GtkWidget* window_init(GtkApplication* app, int width, int height); 

GtkWidget* vbox_init(int spacing, GtkOrientation orientation, int margin_top, int margin_bottom, int margin_start, int margin_end); 

GtkWidget* logo_picture_init(const char* resource_path, gboolean hexpand, gboolean vexpand, GtkAlign align, gboolean can_shrink, GtkContentFit gtk_content_fit); 

GtkWidget* text_field_init();

GtkWidget* save_button_init(const char* label, GtkAlign align, Window_Data *data); 

GtkWidget* hello_world_button_init(const char* default_label, GtkAlign align, GtkWidget* text_field); 

GtkWidget* go_to_my_github_init(const char* default_label, GtkAlign align, GtkWidget* text_field); 

GtkWidget* checkbox1_init(const char* default_label, GtkApplication* app); 

Secret* state_init(GtkWidget* vbox); 

Window_Data* window_data_init(Secret* state, GtkWidget* text_field, GtkWidget* text_field_user_name, AppData* user_data); 

GtkWidget* checkbox2_init(const char* default_label, Secret* state); 

#endif