/*
** BillyScene, 2018
** event_label_mouse_released
** File description:
** bs_label_mouse_released_manager
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Event fired when the mouse is released. This event is used to detect
 * if the mouse is on a label, and if it's the case we fired label's
 * events.
 *
 * @param evt
 * @param frame
 * @param scene
 * @param label
 */
bool bs_label_mouse_released_manager(sfMouseButtonEvent evt, \
bs_frame_t *frame, bs_scene_t *scene, bs_label_t *label)
{
    bs_event_mouse_released_t result;

    if (scene == NULL || label->event_mouse_released == NULL)
        return (false);
    if (!(evt.x <= label->pos.x
    + sfText_getGlobalBounds(label->text).width + label->offset.x \
    && evt.x >= label->pos.x + label->offset.x
    && evt.y <= label->pos.y
    + sfText_getGlobalBounds(label->text).height + label->offset.y &&
    evt.y >= label->pos.y + label->offset.y))
        return (false);
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    label->event_mouse_released(result);
    return (true);
}