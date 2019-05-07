/*
** BillyScene, 2018
** event_label_text_entered
** File description:
** bs_label_text_entered_manager
*/

#include <stdbool.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Handles text entered event on a label in the scene.
 *
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_label_text_entered_manager(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene, bs_label_t *label)
{
    bs_event_text_entered_t result;

    if (label == NULL || label->event_text_entered == NULL)
        return (false);
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    label->event_text_entered(result);
    return (true);
}