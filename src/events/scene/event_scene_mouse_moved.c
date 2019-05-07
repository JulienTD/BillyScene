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

static bool dispatch_scene_mouse_moved_event(bs_list_t *element, \
va_list *args)
{
    sfMouseMoveEvent *evt = (sfMouseMoveEvent *)va_arg(*args, void *);
    bs_frame_t *frame = (bs_frame_t *)va_arg(*args, void *);
    bs_scene_t *scene = (bs_scene_t *)va_arg(*args, void *);

    switch (element->data_type) {
        // case BS_PIXEL_BUFFER:
        //     return bs_pbuffer_render(frame, (bs_pbuffer_t *)element->data);
        // case BS_SPRITE:
        //     return bs_sprite_render(frame , (bs_sprite_t *)element->data);
        // case BS_BUTTON:
        //     return bs_button_render(frame, (bs_button_t *)element->data);
        case BS_LABEL:
            return bs_label_mouse_moved_manager(*evt, frame, scene, \
            (bs_label_t *)element->data);
        // case BS_TEXTFIELD:
        //     return bs_textfield_render(frame, (bs_textfield_t *)element->data);
        default:
            return (false);
    }
}

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

    if (frame)
        bs_sprite_set_pos(frame->cursor, evt.x, evt.y);
    if (scene)
        bs_list_each(&(scene->components_list), \
        &dispatch_scene_mouse_moved_event, &evt, frame, scene);
    if (scene == NULL || scene->event_mouse_moved == NULL)
        return (false);
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_mouse_moved(result);
    return (true);
}