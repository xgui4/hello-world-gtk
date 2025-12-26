#include <gtk/gtk.h>
#include <stdlib.h>
#include <json-glib-1.0/json-glib/json-glib.h>
#include "window.h"
#include "config.h"
#include "AppData.h"
#include "widgets/GTK_Button.h"
#include "utils.h"
#include "myresources.h" // ignore that error 

static void print_hello(GtkWidget *widget, gpointer data)
{
    g_print("Hello World From GTK!\n");
    GtkAlertDialog * popup = gtk_alert_dialog_new("%s", "Hello World from GTK!");

    const char *text = gtk_editable_get_text(GTK_EDITABLE(data));

    const char *buttons[] = {"OK", NULL};

    gtk_alert_dialog_set_buttons(popup, buttons);

    gtk_alert_dialog_set_default_button(popup, 0);

    gtk_alert_dialog_set_modal (popup, TRUE);

    gtk_alert_dialog_set_detail(popup, text);

    GtkRoot *root = gtk_widget_get_root(widget);
    if (GTK_IS_WINDOW(root)) {
        gtk_alert_dialog_show(popup, GTK_WINDOW(root));
        g_print("Modal Alert Dialog did found the parent window. Lanching Dialog \n"); 
    }
    else {
        g_print("Modal Alert Dialog did not found the parent window \n"); 
    }

    g_object_unref(popup);
}

static void go_to_github(GtkButton *button, gpointer app_data) {
    system("xdg-open https://github.com/xgui4/"); 
}

static void send_notification(GtkCheckButton *checkbox, gpointer app_data) {
    gboolean is_active = gtk_check_button_get_active(checkbox);
    if (is_active) {
        system("notify-send -a hellow-world-gtk -i Hello-World-GTK \"Notfication Enable!\""); 
    }
    else {
        system("notify-send -a hellow-world-gtk -i Hello-World-GTK \"Notfication Disabled!\""); 
    }
}

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

static void activate_secret(GtkCheckButton *checkbox, gpointer app_data) {
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

static void save(GtkButton* button, gpointer* data) {

    Window_Data *window_data = (Window_Data*)data;

    AppData *app_data = window_data->app_data; 

    Secret* state = window_data->state; 

    GtkWidget* text_field = window_data->text_field; 

    GtkWidget* text_field_username = window_data->text_field_username; 

    const char * const_txt = gtk_editable_get_text(GTK_EDITABLE(text_field)); 

    if (app_data->msg != const_txt) {
        strcpy(app_data->msg, const_txt); 
    }

    app_data->msg =  gtk_editable_get_text(GTK_EDITABLE(text_field)); 
    if (state->calendar != NULL) {
        app_data->birthday = g_date_time_format(gtk_calendar_get_date(GTK_CALENDAR(state->calendar)), "%Y-%m-%d %H:%M:%S"); 
    }
    
    if (state->secret_entry != NULL) {
        app_data->user_name = gtk_editable_get_text(GTK_EDITABLE(text_field_username)); 
    }

    JsonNode* root = serialize_app_data(app_data); 

    json_node_to_json_file(root, "test.json"); 

    json_node_free(root); 

}

static GtkWidget* window_init(GtkApplication* app, int width, int height) {
    GtkWidget* window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), app_name);
    gtk_window_set_default_size(GTK_WINDOW(window), width, height);
    return window; 
}

static GtkWidget* vbox_init(int spacing, GtkOrientation orientation, int margin_top, int margin_bottom, int margin_start, int margin_end) {
    GtkWidget* vbox = gtk_box_new(orientation, spacing);
    gtk_widget_set_margin_top(vbox, margin_top);
    gtk_widget_set_margin_bottom(vbox, margin_bottom);
    gtk_widget_set_margin_start(vbox, margin_start);
    gtk_widget_set_margin_end(vbox, margin_end);
    return vbox; 
}

static GtkWidget* logo_picture_init(const char* resource_path, gboolean hexpand, gboolean vexpand, GtkAlign align, gboolean can_shrink, GtkContentFit gtk_content_fit) {
    GtkWidget *picture = gtk_picture_new_for_resource(resource_path);
    gtk_widget_set_hexpand(picture, hexpand);
    gtk_widget_set_vexpand(picture, vexpand);
    gtk_widget_set_halign(picture, align);
    gtk_widget_set_valign(picture, align);
    gtk_picture_set_can_shrink(GTK_PICTURE(picture), can_shrink);
    gtk_picture_set_content_fit(GTK_PICTURE(picture), gtk_content_fit);
    return picture;
}

static GtkWidget* text_field_init() {
    GtkWidget *text_field = gtk_entry_new();
    return text_field; 
}

static GtkWidget* save_button_init(const char* label, GtkAlign align, Window_Data *data) {
    GtkWidget *save_button = gtk_button_init(label, align, G_CALLBACK(save), data); 
    return save_button; 
}

static GtkWidget* hello_world_button_init(const char* default_label, GtkAlign align, GtkWidget* text_field) {
    GtkWidget *hello_world_button = gtk_button_new_with_label(default_label);
    gtk_widget_set_halign(hello_world_button, align);
    g_signal_connect(hello_world_button, "clicked", G_CALLBACK(print_hello), text_field);
    return hello_world_button; 
}

static GtkWidget* go_to_my_github_init(const char* default_label, GtkAlign align, GtkWidget* text_field) {
    GtkWidget *go_to_github_button = gtk_button_new_with_label(default_label); 
    gtk_widget_set_halign(go_to_github_button, align);
    g_signal_connect(go_to_github_button, "clicked", G_CALLBACK(go_to_github), text_field);
    return go_to_github_button; 
}

static GtkWidget* checkbox1_init(const char* default_label) {
    GtkWidget *checkbox1 = gtk_check_button_new_with_label(default_label);
    g_signal_connect(checkbox1, "toggled", G_CALLBACK(send_notification), NULL);
    return checkbox1; 
}

static Secret* state_init(GtkWidget* vbox) {
    Secret *state = g_malloc(sizeof(Secret));
    state->vbox = vbox;
    state->calendar = NULL;
    state->secret_entry = NULL; 
    return state; 
}

static GtkWidget* checkbox2_init(const char* default_label, Secret* state) {
    GtkWidget *checkbox2 = gtk_check_button_new_with_label(default_label);
    g_signal_connect(checkbox2, "toggled", G_CALLBACK(activate_secret), state);
    return checkbox2; 
}

void activate(GtkApplication *app, gpointer app_data)
{
    // Initiate app_data
    AppData* user_data = app_data;

    // Window Creation
    GtkWidget *window = window_init(app, 200, 200); 
    GtkWidget *vbox = vbox_init(10, GTK_ORIENTATION_VERTICAL, 10, 10, 10, 10); 

    // Widgets creation
    GtkWidget *logo_picture = logo_picture_init("/dev/xgui4/hello-world-gtk-app/image.jpg", TRUE, TRUE, GTK_ALIGN_FILL, TRUE, GTK_CONTENT_FIT_CONTAIN); 
    GtkWidget *text_field = text_field_init(); 
    GtkWidget *text_field_user_name = text_field_init(); 
    GtkWidget *hello_world_button = hello_world_button_init("Hello World From GTK!", GTK_ALIGN_CENTER, text_field); 
    GtkWidget *go_to_github_button = go_to_my_github_init("Go to my Github", GTK_ALIGN_CENTER, NULL);
    GtkWidget *checkbox1 = checkbox1_init("Activate Notification");
    Secret *state = state_init(vbox); 
    GtkWidget *checkbox2 = checkbox2_init("Activate Secret", state);

    Window_Data *data = g_malloc(sizeof(Window_Data));
    data->state = state; 
    data->text_field = text_field; 
    data->text_field_username = text_field_user_name;
    data->app_data = user_data; 

    GtkWidget *save_button = save_button_init("Save configuraton", GTK_ALIGN_CENTER, data); 

    // Load the widgets (with the good orders)
    gtk_box_append(GTK_BOX(vbox), logo_picture);
    gtk_box_append(GTK_BOX(vbox), text_field);
    gtk_box_append(GTK_BOX(vbox), text_field_user_name);
    gtk_box_append(GTK_BOX(vbox), hello_world_button);
    gtk_box_append(GTK_BOX(vbox), checkbox1); 
    gtk_box_append(GTK_BOX(vbox), checkbox2); 
    gtk_box_append(GTK_BOX(vbox), go_to_github_button);
    // gtk_box_append(GTK_BOX(vbox), save_button);  need to be fixed

    // boilerplate code for loading and showing the window
    gtk_window_present(GTK_WINDOW(window));
    gtk_window_set_child(GTK_WINDOW(window), vbox);
}