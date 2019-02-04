/*
** BillyScene, 2019
** scene_refresh
** File description:
** scene_refresh
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

static short get_layer(bs_list_t *list)
{
    if (list == NULL)
        return (0);
    switch (list->data_type) {
        case BS_PIXEL_BUFFER:
            return ((bs_pbuffer_t *)list->data)->layer;
        case BS_SPRITE:
            return ((bs_sprite_t *)list->data)->layer;
        case BS_LABEL:
            return ((bs_label_t *)list->data)->layer;
        case BS_TEXTFIELD:
            return ((bs_textfield_t *)list->data)->layer;
        case BS_BUTTON:
            return ((bs_button_t *)list->data)->layer;
        default:
            return (0);
    }
}

static bool is_id_in_tab(int id, int *id_used, bs_list_t *list)
{
    int length = bs_list_length(&list);

    for (int i = 0; i < length; i++) {
        if (id_used[i] == id)
            return (true);
    }
    return (false);
}

static bs_list_t *get_max_layer(bs_list_t *list, int *id_used)
{
    bs_list_t *curr = NULL;
    int max = 0;
    bs_list_t *list_max = NULL;

    if (list == NULL || id_used == NULL)
        return (NULL);
    for (curr = list; curr != NULL; curr = curr->next) {
        if (is_id_in_tab(curr->id, id_used, list) == true)
            continue;
        if (list_max == NULL) {
            list_max = curr;
            max = get_layer(curr);
        } else if (get_layer(curr) > max) {
            list_max = curr;
            max = get_layer(curr);
        }
    }
    return (list_max);
}

static bool reorder_component_list(bs_scene_t *scene, \
int *id_used, int length)
{
    bs_list_t *cpy = NULL;
    bs_list_t *element = NULL;
    bs_list_t *tmp = NULL;

    cpy = scene->components_list;
    scene->components_list = NULL;
    for (int i = 0; i < length; i++) {
        element = bs_list_get_by_id(&cpy, id_used[i]);
        if (element == NULL)
            continue;
        element = bs_list_create(element->data, element->data_type);
        if (scene->components_list == NULL) {
            scene->components_list = element;
        } else {
            tmp = scene->components_list;
            scene->components_list = element;
            element->next = tmp;
        }
    }
    return (true);
}

bool bs_scene_refresh(bs_scene_t *scene)
{
    int length = bs_list_length(&(scene->components_list));
    int id_used[length];
    bs_list_t *min_layer_component = NULL;

    for (int i = 0; i < length; i++)
        id_used[i] = -1;
    min_layer_component = get_max_layer(scene->components_list, id_used);
    for (int i = 0; min_layer_component != NULL; i++) {
        min_layer_component = get_max_layer(scene->components_list, id_used);
        if (min_layer_component == NULL)
            break;
        id_used[i] = min_layer_component->id;
    }
    return (reorder_component_list(scene, id_used, length));
}