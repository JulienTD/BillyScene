/*
** BillyScene, 2018
** event_label_mouse_wheel_scrolled
** File description:
** bs_label_mouse_wheel_scrolled_manager
*/

#include <stdbool.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Handles mouse scroll wheel event on a label in the scene.
 *
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_label_mouse_wheel_scrolled_manager(sfMouseWheelScrollEvent evt, \
bs_frame_t *frame, bs_scene_t *scene, bs_label_t *label)
{
    bs_event_mouse_wheel_scrolled_t result;

    if (label == NULL || label->event_mouse_wheel_scrolled == NULL) {
        return false;
    }
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    label->event_mouse_wheel_scrolled(result);
    return true;
}