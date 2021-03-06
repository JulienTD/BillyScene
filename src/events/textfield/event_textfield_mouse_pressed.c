/*
** BillyScene, 2018
** event_textfield_mouse_pressed
** File description:
** bs_textfield_mouse_pressed_manager
*/

#include <stdbool.h>
#include "bs_components.h"
#include "bs_events.h"
#include "bs_prototypes.h"

static bool execute_focus_event(bs_textfield_t *textfield, 
sfMouseButtonEvent event, bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_textfield_focus_t result;

    if (textfield == NULL || textfield->focus_event == NULL) {
        return (false);
    }
    result.event = event;
    result.frame = frame;
    result.textfield = textfield;
    result.scene = scene;
    textfield->focus_event(result);
    return (true);
}

static bool execute_unfocus_event(bs_textfield_t *textfield, 
sfMouseButtonEvent event, bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_textfield_unfocus_t result;

    if (textfield == NULL || textfield->unfocus_event == NULL) {
        return (false);
    }
    result.event = event;
    result.frame = frame;
    result.textfield = textfield;
    result.scene = scene;
    textfield->unfocus_event(result);
    return (true);
}

/**
 * @brief Event fired when the mouse is pressed. This event is used to detect
 * if the mouse is on a textfield, and if it's the case we set it to focus
 * 
 */
void bs_textfield_mouse_pressed_manager(sfMouseButtonEvent event, \
bs_frame_t *frame, bs_scene_t *scene)
{
    bs_list_t *curr = NULL;
    bs_textfield_t *tf = NULL;

    if (event.button != sfMouseLeft || scene == NULL)
        return;
    for (curr = scene->components_list; curr != NULL; curr = curr->next) {
        if (curr->data_type != BS_TEXTFIELD)
            continue;
        tf = (bs_textfield_t *)curr->data;
        if (tf->enabled == true && \
        bs_is_mouse_on_textfield(*(tf), event.x, event.y) == true) {
            tf->is_focus = true;
            execute_focus_event(tf, event, frame, scene);
        } else if (tf->is_focus == true) {
            tf->is_focus = false;
            execute_unfocus_event(tf, event, frame, scene);
        } else {
            tf->is_focus = false;
        }
    }
}
