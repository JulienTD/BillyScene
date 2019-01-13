/*
** EPITECH PROJECT, 2017
** scene_manager
** File description:
** scene_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Gets scene by its id
 * 
 * @param frame 
 * @param id 
 * @return bs_scene_t* 
 */
bs_scene_t *bs_scene_get_by_id(bs_frame_t *frame, char *id)
{
    bs_list_t *curr = NULL;
    bs_scene_t *scene = NULL;

    if (frame == NULL || id == NULL)
        return (NULL);
    curr = frame->scenes;
    while (curr) {
        scene = (bs_scene_t *)curr->data;
        if (bs_str_are_equals(id, scene->id_scene)) {
            return (scene);
        }
        curr = curr->next;
    }
    return (NULL);
}
