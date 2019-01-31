/*
** BillyScene, 2017
** scene_add_to_frame
** File description:
** bs_scene_add_to_frame
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Adds scene to frame
 * 
 * @param frame
 * @param scene
 * @return true
 * @return false
 */
bool bs_scene_add_to_frame(bs_frame_t *frame, bs_scene_t *scene)
{
    if (frame == NULL || scene == NULL)
        return (false);
    return bs_list_push(&(frame->scenes), scene, BS_SCENE) != NULL;
}
