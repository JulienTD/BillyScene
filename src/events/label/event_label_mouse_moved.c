/*
** BillyScene, 2018
** event_scene_mouse_moved
** File description:
** bs_scene_mouse_moved_manager
*/

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Event fired when the mouse is moving. This event is used to detect
 * if the mouse is on a label component, and if it's the case we fire the label's
 * events.
 *
 * @param evt
 * @param frame
 * @param scene
 * @param label
 * @return true
 * @return false
 */
bool bs_label_mouse_moved_manager(sfMouseMoveEvent evt, bs_frame_t *frame, \
bs_scene_t *scene, bs_label_t *label)
{
    bs_event_mouse_moved_t result;

    if (scene == NULL || label->event_mouse_moved == NULL)
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
    label->event_mouse_moved(result);
    return (true);
}