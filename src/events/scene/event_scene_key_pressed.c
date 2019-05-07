/*
** BillyScene, 2018
** event_scene_key_pressed
** File description:
** bs_scene_key_pressed_manager
*/

#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

static bool dispatch_scene_key_pressed_event(bs_list_t *element, \
va_list *args)
{
    sfKeyEvent *evt = (sfKeyEvent *)va_arg(*args, void *);
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
            return bs_label_key_pressed_manager(*evt, frame, scene, \
            (bs_label_t *)element->data);
        // case BS_TEXTFIELD:
        //     return bs_textfield_render(frame, (bs_textfield_t *)element->data);
        default:
            return (false);
    }
}

/**
 * @brief Handles scene Key press event
 *
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_scene_key_pressed_manager(sfKeyEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
    bs_event_key_pressed_t result;

    if (scene)
        bs_list_each(&scene->components_list, \
        &dispatch_scene_key_pressed_event, &evt, frame, scene);
    if (scene == NULL || scene->event_key_pressed == NULL)
        return (false);
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_key_pressed(result);
    return (true);
}