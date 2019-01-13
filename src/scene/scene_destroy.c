/*
** EPITECH PROJECT, 2017
** scene_manager
** File description:
** scene_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

static void destroy_components(bs_list_t *list)
{
    if (list == NULL)
        return;
    if (list->data_type == BS_BUTTON)
        bs_button_destroy(list->data);
    if (list->data_type == BS_LABEL)
        bs_label_destroy(list->data);
    if (list->data_type == BS_SPRITE)
        bs_sprite_destroy(list->data);
    if (list->data_type == BS_TEXTFIELD)
        bs_textfield_destroy(list->data);
    if (list->data_type == BS_PIXEL_BUFFER)
        bs_pbuffer_destroy(list->data);
}

/**
 * @brief Destroys scene
 * 
 * @param id  
 */
void bs_scene_destroy(bs_scene_t *scene)
{
    if (scene == NULL)
        return;
    if (scene->id_scene)
        free(scene->id_scene);
    bs_list_destroy(&(scene->components_list), &destroy_components);
    free(scene);
}
