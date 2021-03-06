/*
** BillyScene, 2017
** button_add_to_scene
** File description:
** bs_button_add_to_scene
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Adds button to scene
 * 
 * @param scene
 * @param button
 * @return true
 * @return false
 */
bool bs_button_add_to_scene(bs_scene_t *scene, bs_button_t *button)
{
    if (scene == NULL || button == NULL)
        return (false);
    return bs_list_push(&(scene->components_list), button, BS_BUTTON) != NULL;
}