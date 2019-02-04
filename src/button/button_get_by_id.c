/*
** BillyScene, 2018
** button_get_by_id
** File description:
** bs_button_get_by_id
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Gets button in a scene by its id
 * 
 * @param scene
 * @param id
 * @return bs_button_t*
 */
bs_button_t *bs_button_get_by_id(bs_scene_t *scene, char *id)
{
    bs_list_t *curr = NULL;
    bs_button_t *button = NULL;

    if (scene == NULL || id == NULL)
        return (NULL);
    for (curr = scene->components_list; curr != NULL; curr = curr->next) {
        if (curr->data_type != BS_BUTTON)
            continue;
        button = (bs_button_t *)curr->data;
        if (bs_str_are_equals(id, button->id_button))
            return (button);
    }
    return (NULL);
}
