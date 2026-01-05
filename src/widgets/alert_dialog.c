#include "alert_dialog.h"
#include <gtk/gtk.h>

GtkAlertDialog* gtk_simple_alert_dialog_create(const char* title, const char* body, const char* buttons[], gboolean is_modal) {
    GtkAlertDialog * popup = gtk_alert_dialog_new("%s", title);

    gtk_alert_dialog_set_buttons(popup, buttons);
    gtk_alert_dialog_set_default_button(popup, 0);
    gtk_alert_dialog_set_modal (popup, is_modal);
    gtk_alert_dialog_set_detail(popup, body);

    return popup; 
}

gboolean gtk_simple_alert_dialog_show(GtkWidget *widget, GtkAlertDialog *popup)
{
    GtkRoot *root = gtk_widget_get_root(widget);
    if (GTK_IS_WINDOW(root)) {
        gtk_alert_dialog_show(popup, GTK_WINDOW(root));
    }
    else {
        g_print("Modal Alert Dialog did not found the parent window \n"); 
        return FALSE; 
    }

    return TRUE; 
}
