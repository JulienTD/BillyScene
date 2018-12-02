/*
** EPITECH PROJECT, 2018
** Function: bs_scene_render
** File description:
** Tests the function bs_scene_render
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

void tick_event(bs_event_tick_t event);

void tick_event(bs_event_tick_t event __attribute__((unused)))
{
	cr_assert(true);
}

Test(bs_scene_render, basic) {
	bs_frame_t *frame = bs_frame_create();
	bs_scene_t *scene = bs_scene_create("test");
	sfVideoMode mode = {100, 100, 32};
	bool status = false;

	cr_assert_not_null(frame);
	cr_assert_not_null(scene);
	frame->window = sfRenderWindow_create(mode, "Billy Scene", \
	sfClose, NULL);
	scene->event_tick = &tick_event;
	scene->current_tick = 100;
	bs_scene_add_to_frame(frame, scene);
	status = bs_scene_render(scene, frame);
	cr_assert(status == true);
	bs_frame_destroy(frame);
}

Test(bs_scene_render, null_scene) {
	bs_frame_t *frame = bs_frame_create();
	bs_scene_t *scene = NULL;
	sfVideoMode mode = {100, 100, 32};
	bool status = false;

	cr_assert_not_null(frame);
	frame->window = sfRenderWindow_create(mode, "Billy Scene", \
	sfClose, NULL);
	status = bs_scene_render(scene, frame);
	cr_assert(status == false);
}

Test(bs_scene_render, null_frame) {
	bs_frame_t *frame = NULL;
	bs_scene_t *scene = bs_scene_create("test");
	bool status = false;

	cr_assert_not_null(scene);
	status = bs_scene_render(scene, frame);
	cr_assert(status == false);
}