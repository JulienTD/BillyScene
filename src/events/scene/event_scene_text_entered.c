/*
** BillyScene, 2018
** event_scene_text_entered
** File description:
** bs_scene_text_entered_manager
*/

#include <stdbool.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

static bool dispatch_scene_text_entered_event(bs_list_t *element, \
va_list *args)
{
    sfTextEvent *evt = (sfTextEvent *)va_arg(*args, void *);
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
            return bs_label_text_entered_manager(*evt, frame, scene, \
            (bs_label_t *)element->data);
        // case BS_TEXTFIELD:
        //     return bs_textfield_render(frame, (bs_textfield_t *)element->data);
        default:
            return (false);
    }
}

static bool fill_scene_textfields(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
    bs_list_t *curr = NULL;
    bs_textfield_t *textfield = NULL;

    if (scene == NULL || frame == NULL) {
        return false;
    }
    for (curr = scene->components_list; curr != NULL; curr = curr->next) {
        if (curr->data_type != BS_TEXTFIELD)
            continue;
        textfield = (bs_textfield_t *)curr->data;
        if (textfield->is_focus) {
            bs_textfield_text_entered_manager(textfield, evt, \
            frame, scene);
        }
    }
    return (true);
}

/**
 * @brief Handles Text Entered event in the scene.
 * 
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_scene_text_entered_manager(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
    bs_event_text_entered_t result;

    if (scene)
        bs_list_each(&(scene->components_list), \
        &dispatch_scene_text_entered_event, &evt, frame, scene);
    fill_scene_textfields(evt, frame, scene);
    if (scene == NULL || scene->event_text_entered == NULL)
        return (false);
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_text_entered(result);
    return (true);
}