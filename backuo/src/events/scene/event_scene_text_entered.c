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

bool bs_scene_text_entered_manager(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
	bs_event_text_entered_t result;

	if (scene->event_text_entered == NULL) {
		return false;
	}
	result.event = evt;
	result.frame = frame;
	result.scene = scene;
	scene->event_text_entered(result);
	return true;
}