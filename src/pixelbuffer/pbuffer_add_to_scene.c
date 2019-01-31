/*
** BillyScene, 2018
** pbuffer_add_to_scene
** File description:
** bs_pbuffer_add_to_scene
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Adds pbuffer to the scene
 * 
 * @param scene
 * @param pbuffer
 * @return true
 * @return false
 */
bool bs_pbuffer_add_to_scene(bs_scene_t *scene, bs_pbuffer_t *pbuffer)
{
    if (scene == NULL || pbuffer == NULL)
        return (false);
    return bs_list_push(&(scene->components_list), pbuffer, \
    BS_PIXEL_BUFFER) != NULL;
}
