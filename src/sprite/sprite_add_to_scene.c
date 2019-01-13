/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Adds sprite to the scene
 * 
 * @param scene 
 * @param sprite 
 * @return true 
 * @return false 
 */
bool bs_sprite_add_to_scene(bs_scene_t *scene, bs_sprite_t *sprite)
{
    if (scene == NULL || sprite == NULL)
        return false;
    return bs_list_push(&(scene->components_list), sprite, BS_SPRITE) != NULL;
}
