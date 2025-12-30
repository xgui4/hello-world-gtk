#include "app_data.h"
#include "json-glib-1.0/json-glib/json-glib.h"

JsonNode* serialize_app_data(AppData *self) {
    JsonObject *obj = json_object_new(); 

    gchar* username = "NONE"; 
    gchar* msg = "NONE"; 
    gchar* birthday = "NONE"; 
    gchar* secret = "NONE"; 

    if (self->user_name != NULL) { username = g_strdup(self->user_name); }
    if (self->msg != NULL)  { msg = g_strdup(self->msg); }
    if (self->birthday != NULL) { birthday = g_strdup(self->birthday); }
    // if (self->secret != NULL) { secret = g_strdup(self->secret); }

    json_object_set_string_member(obj, "user_name", username);
    json_object_set_string_member(obj, "msg",       msg);
    json_object_set_string_member(obj, "birthday",  birthday);
    json_object_set_string_member(obj, "secret",    secret);

    JsonNode *root = json_node_new(JSON_NODE_OBJECT);
    json_node_set_object(root, obj);

    return root;
}