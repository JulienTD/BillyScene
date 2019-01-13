/*
** EPITECH PROJECT, 2018
** mouse_button_pressed_event
** File description:
** Button event
*/

#include "bs_components.h"
#include "bs_events.h"
#include "bs_prototypes.h"
#include "stdbool.h"

static bool execute_pressed_event(bs_button_t *button, 
sfMouseButtonEvent event, bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_button_click_pressed_t result;

    if (button == NULL || button->click_pressed_event == NULL) {
        return false;
    }
    result.event = event;
    result.frame = frame;
    result.button = button;
    result.scene = scene;
    button->click_pressed_event(result);
    return true;
}

/**
 * @brief Event fired when the mouse is pressed. This event is used to detect
 * jf the mouse is on a button, and if it's the case we fired button's
 * events.
 * 
 */
void bs_button_mouse_pressed_manager(sfMouseButtonEvent event, \
bs_frame_t *frame, bs_scene_t *scene)
{
    bs_list_t *curr = NULL;
    bs_button_t *button = NULL;

    if (event.button != sfMouseLeft || scene == NULL)
        return;
    for (curr = scene->components_list; curr != NULL; curr = curr->next) {
        if (curr->data_type != BS_BUTTON)
            continue;
        button = (bs_button_t *)curr->data;
        if (button->enabled == true && \
        bs_is_mouse_on_button(*(button), event.x, event.y) == true) {
            execute_pressed_event(button, event, frame, scene);
            button->status = CLICKED;
        }
    }
}
