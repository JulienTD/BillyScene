/*
** EPITECH PROJECT, 2018
** render_scene
** File description:
** render_scene
*/

#include "bs_components.h"
#include "bs_events.h"
#include "bs_prototypes.h"
#include "stdbool.h"

static bool execute_tick_event(bs_frame_t *frame, bs_scene_t *scene)
{
	bs_event_tick_t result;

	if (scene == NULL || scene->event_tick == NULL) {
		return false;
	}
	result.frame = frame;
	result.scene = scene;
	scene->event_tick(result);
	return true;
}

static bool render_components(bs_list_t **head, bs_frame_t *frame, \
bool (*func_render)(bs_frame_t *f, void *component))
{
	bs_list_t *curr = NULL;

	if (head == NULL)
		return (true);
	curr = *head;
	while (curr) {
		if (func_render != NULL) {
			func_render(frame, curr->data);
		}
		curr = curr->next;
	}
	return (true);
}

/**
 * @brief Renders scene
 * 
 * @param scene 
 * @param frame 
 * @return true 
 * @return false 
 */
bool bs_scene_render(bs_scene_t *scene, bs_frame_t *frame)
{
	if (scene == NULL || frame == NULL)
		return (-1);
	if (scene->current_tick > frame->max_tick) {
		scene->current_tick = 0;
	}
	execute_tick_event(frame, scene);
	render_components(&(scene->sprite_list), frame, \
		(_Bool (*)(bs_frame_t *, void *))&bs_sprite_render);
	render_components(&(scene->button_list), frame, \
		(_Bool (*)(bs_frame_t *, void *))&bs_button_render);
	render_components(&(scene->label_list), frame, \
		(_Bool (*)(bs_frame_t *, void *))&bs_label_render);
	render_components(&(scene->textfield_list), frame, \
		(_Bool (*)(bs_frame_t *, void *))&bs_textfield_render);
	render_components(&(scene->pbuffer_list), frame, \
		(_Bool (*)(bs_frame_t *, void *))&bs_pbuffer_render);
	scene->current_tick++;
	return (1);
}
