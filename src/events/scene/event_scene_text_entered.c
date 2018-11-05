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

static bool fill_scene_textfields(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
	bs_list_t *curr = NULL;
	bs_textfield_t *textfield = NULL;

	if (scene == NULL || frame == NULL) {
		return false;
	}
	curr = scene->textfield_list;
	while (curr) {
		textfield = (bs_textfield_t *)curr->data;		
		if (textfield->is_focus) {
			bs_textfield_text_entered_manager(textfield, evt, \
			frame, scene);
		}
		curr = curr->next;
	}
	return (true);
}

bool bs_scene_text_entered_manager(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
	bs_event_text_entered_t result;

	fill_scene_textfields(evt, frame, scene);
	if (scene == NULL || scene->event_text_entered == NULL) {
		return false;
	}
	result.event = evt;
	result.frame = frame;
	result.scene = scene;
	scene->event_text_entered(result);
	return true;
}