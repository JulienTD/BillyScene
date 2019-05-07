/*
** BillyScene, 2018
** event_scene_mouse_pressed
** File description:
** bs_scene_mouse_pressed_manager
*/

#include <stdbool.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

static bool dispatch_scene_mouse_pressed_event(bs_list_t *element, \
va_list *args)
{
    sfMouseButtonEvent *evt = (sfMouseButtonEvent *)va_arg(*args, void *);
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
            return bs_label_mouse_pressed_manager(*evt, frame, scene, \
            (bs_label_t *)element->data);
        // case BS_TEXTFIELD:
        //     return bs_textfield_render(frame, (bs_textfield_t *)element->data);
        default:
            return (false);
    }
}

/**
 * @brief Handles Mouse click event in the scene.
 *
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_scene_mouse_pressed_manager(sfMouseButtonEvent evt, \
bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_mouse_pressed_t result;

    if (scene)
        bs_list_each(&(scene->components_list), \
        &dispatch_scene_mouse_pressed_event, &evt, frame, scene);
    bs_textfield_mouse_pressed_manager(evt, frame, scene);
    if (scene == NULL || scene->event_mouse_pressed == NULL)
        return false;
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_mouse_pressed(result);
    return true;
}