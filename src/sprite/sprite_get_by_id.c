/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Gets a sprite by its id
 * 
 * @param scene 
 * @param id 
 * @return bs_sprite_t* 
 */
bs_sprite_t *bs_sprite_get_by_id(bs_scene_t *scene, char *id)
{
    bs_list_t *curr = NULL;
    bs_sprite_t *sprite = NULL;

    if (scene == NULL || id == NULL)
        return NULL;
    for (curr = scene->components_list; curr != NULL; curr = curr->next) {
        if (curr->data_type != BS_SPRITE)
            continue;
        sprite = (bs_sprite_t *)curr->data;
        if (bs_str_are_equals(id, sprite->id_sprite))
            return (sprite);
    }
    return (NULL);
}
