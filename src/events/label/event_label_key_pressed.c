/*
** BillyScene, 2018
** event_label_key_pressed
** File description:
** bs_label_key_pressed_manager
*/

#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Handles label key press event
 *
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_label_key_pressed_manager(sfKeyEvent evt, bs_frame_t *frame, \
bs_scene_t *scene, bs_label_t *label)
{
    bs_event_key_pressed_t result;

    if (label == NULL || label->event_key_pressed == NULL)
        return (false);
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    label->event_key_pressed(result);
    return (true);
}