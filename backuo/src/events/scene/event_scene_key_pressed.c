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

bool bs_scene_key_pressed_manager(sfKeyEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
	bs_event_key_pressed_t result;

	if (scene->event_key_pressed == NULL) {
		return false;
	}
	result.event = evt;
	result.frame = frame;
	result.scene = scene;
	scene->event_key_pressed(result);
	return true;
}