/*
** BillyScene, 2018
** label_add_to_scene
** File description:
** bs_label_add_to_scene
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Adds label to the scene
 * 
 * @param scene
 * @param label
 * @return true
 * @return false
 */
bool bs_label_add_to_scene(bs_scene_t *scene, bs_label_t *label)
{
    if (scene == NULL || label == NULL)
        return (false);
    return bs_list_push(&(scene->components_list), label, BS_LABEL) != NULL;
}
