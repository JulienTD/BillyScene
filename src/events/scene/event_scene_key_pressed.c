/*
** BillyScene, 2018
** event_scene_key_pressed
** File description:
** bs_scene_key_pressed_manager
*/

#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Handles scene Key press event
 * 
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_scene_key_pressed_manager(sfKeyEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
    bs_event_key_pressed_t result;

    if (scene == NULL || scene->event_key_pressed == NULL) {
        return false;
    }
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_key_pressed(result);
    return true;
}