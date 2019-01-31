/*
** BillyScene, 2018
** event_scene_mouse_released
** File description:
** bs_scene_mouse_released_manager
*/

#include <stdbool.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Handles Mouse click release event in the scene.
 * 
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_scene_mouse_released_manager(sfMouseButtonEvent evt, \
bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_mouse_released_t result;

    if (scene == NULL || scene->event_mouse_released == NULL) {
        return false;
    }
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_mouse_released(result);
    return true;
}