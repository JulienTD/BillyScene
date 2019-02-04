/*
** BillyScene, 2018
** event_button_mouse_move
** File description:
** bs_button_mouse_move_manager
*/

#include "bs_components.h"
#include "bs_events.h"
#include "bs_prototypes.h"
#include <stdbool.h>

static bool execute_hover_in_event(bs_button_t *button, \
sfMouseMoveEvent event, bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_button_hover_in_t result;

    if (button == NULL || button->hover_in_event == NULL) {
        return false;
    }
    result.event = event;
    result.frame = frame;
    result.button = button;
    result.scene = scene;
    button->hover_in_event(result);
    return true;
}

static bool execute_hover_out_event(bs_button_t *button, \
sfMouseMoveEvent event, bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_button_hover_out_t result;

    if (button == NULL || button->hover_out_event == NULL) {
        return false;
    }
    result.event = event;
    result.frame = frame;
    result.button = button;
    result.scene = scene;
    button->hover_out_event(result);
    return true;
}

static bool execute_hover_event(bs_button_t *button, \
sfMouseMoveEvent event, bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_button_hover_t result;

    if (button == NULL || button->hover_event == NULL) {
        return false;
    }
    result.event = event;
    result.frame = frame;
    result.button = button;
    result.scene = scene;
    button->hover_event(result);
    return true;
}

static void bs_mouse_button_move_event(sfMouseMoveEvent event, \
bs_frame_t *frame, bs_scene_t *scene, bs_button_t *button)
{
    if (bs_is_mouse_on_button(*(button), event.x, event.y)) {
        if (button->status == NORMAL) {
            execute_hover_in_event(button, event, frame, scene);
            bs_sound_play(button->sound_hover_in);
        }
        execute_hover_event(button, event, frame, scene);
        button->status = HOVERED;
    } else {
        if (button->status == HOVERED) {
            execute_hover_out_event(button, event, frame, scene);
            bs_sound_play(button->sound_hover_out);
        }
        button->status = NORMAL;
    }
}

/**
 * @brief Event fired when the mouse is moving. This event is used to detect
 * if the mouse is on a button component, and if it's the case we fire the button's
 * events.
 * 
 */
void bs_button_mouse_move_manager(sfMouseMoveEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
    bs_list_t *curr = NULL;
    bs_button_t *button = NULL;

    if (scene == NULL)
        return;
    for (curr = scene->components_list; curr != NULL; curr = curr->next) {
        if (curr->data_type != BS_BUTTON)
            continue;
        button = (bs_button_t *)curr->data;
        if (button->enabled == true)
            bs_mouse_button_move_event(evt, frame, scene, button);
    }
}
