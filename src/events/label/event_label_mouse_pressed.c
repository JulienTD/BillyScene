/*
** BillyScene, 2018
** event_label_mouse_pressed
** File description:
** bs_label_mouse_pressed_manager
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Event fired when the mouse is pressed. This event is used to detect
 * if the mouse is on a label component, and if it's the case we fire label's
 * events.
 *
 * @param evt
 * @param frame
 * @param scene
 * @param label
 */
bool bs_label_mouse_pressed_manager(sfMouseButtonEvent evt, \
bs_frame_t *frame, bs_scene_t *scene, bs_label_t *label)
{
    bs_event_mouse_pressed_t result;

    if (scene == NULL || label->event_mouse_pressed == NULL)
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
    label->event_mouse_pressed(result);
    return (true);
}