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
	bs_scene_render_all_sprites(scene, frame);
	bs_scene_render_all_buttons(scene, frame);
	bs_scene_render_all_labels(scene, frame);
	bs_scene_render_all_textfields(scene, frame);
	scene->current_tick++;
	return (1);
}
