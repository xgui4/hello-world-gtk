#include <gtk/gtk.h>
#include <stdlib.h>
#include <json-glib-1.0/json-glib/json-glib.h>
#include "window.h"
#include "config.h"
#include "app_data.h"
#include "widgets/button.h"
#include "utils.h"
#include "widgets/alert_dialog.h"
#include "myresources.h" // ignore that error 
#include "window_init.h"

static void load_widgets(
    GtkWidget *vbox, 
    GtkWidget *logo_picture, 
    GtkWidget *text_field, 
    GtkWidget *text_field_user_name, 
    GtkWidget *hello_world_button, 
    GtkWidget *checkbox1, 
    GtkWidget *checkbox2, 
    GtkWidget *calendar,
    GtkWidget *go_to_github_button, 
    GtkWidget *save_button
){
    gtk_box_append(GTK_BOX(vbox), logo_picture);
    gtk_box_append(GTK_BOX(vbox), text_field);
    gtk_box_append(GTK_BOX(vbox), text_field_user_name);
    gtk_box_append(GTK_BOX(vbox), hello_world_button);
    gtk_box_append(GTK_BOX(vbox), checkbox1);
    gtk_box_append(GTK_BOX(vbox), checkbox2);
    gtk_box_append(GTK_BOX(vbox), calendar); 
    gtk_box_append(GTK_BOX(vbox), go_to_github_button);
    gtk_box_append(GTK_BOX(vbox), save_button);
}

void activate(GtkApplication *app, gpointer app_data)
{
    // Initiate app_data
    AppData* user_data = app_data;

    // Window Creation
    GtkWidget *window = window_init(app, 200, 200); 
    GtkWidget *vbox = vbox_init(10, GTK_ORIENTATION_VERTICAL, 10, 10, 10, 10); 

    // Widgets creation
    GtkWidget *logo_picture = logo_picture_init(app_image_path, TRUE, TRUE, GTK_ALIGN_FILL, TRUE, GTK_CONTENT_FIT_CONTAIN); 
    GtkWidget *text_field = text_field_init(); 
    GtkWidget *text_field_user_name = text_field_init(); 
    GtkWidget *hello_world_button = hello_world_button_init("Hello World From GTK!", GTK_ALIGN_CENTER, text_field); 
    GtkWidget *go_to_github_button = go_to_my_github_init("Go to my Github", GTK_ALIGN_CENTER, NULL);
    GtkWidget *checkbox1 = checkbox1_init("Activate Notification", app);
    Secret *state = state_init(vbox); 
    GtkWidget *checkbox2 = checkbox2_init("Activate Secret", state);
    GtkWidget *calendar = calendar_init(); 
    Window_Data *data = window_data_init(state, text_field, text_field_user_name, user_data);
    GtkWidget *save_button = save_button_init("Save configuraton", GTK_ALIGN_CENTER, data); 

    load_widgets(
        vbox, 
        logo_picture, 
        text_field, 
        text_field_user_name, 
        hello_world_button, 
        checkbox1, 
        checkbox2, 
        calendar,
        go_to_github_button, 
        save_button
    );

    // boilerplate code for loading and showing the window
    gtk_window_present(GTK_WINDOW(window));
    gtk_window_set_child(GTK_WINDOW(window), vbox);
}