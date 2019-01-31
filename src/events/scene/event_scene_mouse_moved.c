/*
** BillyScene, 2018
** event_scene_mouse_moved
** File description:
** bs_scene_mouse_moved_manager
*/

#include <stdbool.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Event fired when the mouse is moving in the scene.
 * 
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_scene_mouse_moved_manager(sfMouseMoveEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
    bs_event_mouse_moved_t result;

    bs_sprite_set_pos(frame->cursor, evt.x, evt.y);
    if (scene == NULL || scene->event_mouse_moved == NULL) {
        return (false);
    }
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_mouse_moved(result);
    return (true);
}