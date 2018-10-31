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

bool bs_scene_mouse_wheel_scrolled_manager(sfMouseWheelScrollEvent evt, \
bs_frame_t *frame, bs_scene_t *scene)
{
	bs_event_mouse_wheel_scrolled_t result;

	if (scene->event_mouse_wheel_scrolled == NULL) {
		return false;
	}
	result.event = evt;
	result.frame = frame;
	result.scene = scene;
	scene->event_mouse_wheel_scrolled(result);
	return true;
}