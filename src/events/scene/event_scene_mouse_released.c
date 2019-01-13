/*
** EPITECH PROJECT, 2018
** key_pressed_event
** File description:
** key_pressed_event
*/

#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

bool bs_scene_mouse_released_manager(sfMouseButtonEvent evt, \
bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_mouse_released_t result;

    if (scene == NULL || scene->event_mouse_released == NULL) {
        return false;
    }
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_mouse_released(result);
    return true;
}