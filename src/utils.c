#include <stdio.h>
#include "utils.h"
#include <string.h>

int contains_argument(int argc, char *argv[], const char *target) {
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
