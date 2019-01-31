/*
** BillyScene, 2018
** event_scene_mouse_wheel_scrolled
** File description:
** bs_scene_mouse_wheel_scrolled_manager
*/

#include <stdbool.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Handles Mouse scroll wheel event in the scene.
 * 
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_scene_mouse_wheel_scrolled_manager(sfMouseWheelScrollEvent evt, \
bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_mouse_wheel_scrolled_t result;

    if (scene == NULL || scene->event_mouse_wheel_scrolled == NULL) {
        return false;
    }
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_mouse_wheel_scrolled(result);
    return true;
}