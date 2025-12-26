#include "AppData.h"
#include "json-glib-1.0/json-glib/json-glib.h"

JsonNode* serialize_app_data(AppData *data) {
    JsonObject *obj = json_object_new(); 

    json_object_set_string_member(obj, "user_name", data->user_name ? data->user_name : "Error");
    json_object_set_string_member(obj, "msg",       data->msg       ? data->msg       : "Error");
    json_object_set_string_member(obj, "birthday",  data->birthday  ? data->birthday  : "Error");
    json_object_set_string_member(obj, "secret",    data->secret    ? data->secret    : "Error");

    JsonNode *root = json_node_new(JSON_NODE_OBJECT);
    json_node_set_object(root, obj);

    return root;
}