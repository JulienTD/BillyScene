/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Adds textfield to scene
 * 
 * @param scene 
 * @param sprite 
 * @return true 
 * @return false 
 */
bool bs_textfield_add_to_scene(bs_scene_t *scene, bs_textfield_t *textfield)
{
    if (scene == NULL || textfield == NULL)
        return false;
    return bs_list_push(&(scene->components_list), textfield, \
    BS_TEXTFIELD) != NULL;
}
