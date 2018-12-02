/*
** EPITECH PROJECT, 2018
** Function: bs_scene_set_to
** File description:
** Tests the function bs_scene_set_to
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

void event_init(bs_event_scene_init_t event);

void event_init(bs_event_scene_init_t event __attribute__((unused)))
{
	cr_assert(true);
}

Test(bs_scene_set_to, basic) {
	bs_frame_t *frame = bs_frame_create();
	bs_scene_t *scene_1 = bs_scene_create("1");
	bool status = false;

	scene_1->event_init = &event_init;
	scene_1->event_init_post = &event_init;
	bs_scene_add_to_frame(frame, scene_1);
	status = bs_scene_set_to(frame, "1");
	cr_assert(status == true);
	bs_frame_destroy(frame);
}

Test(bs_scene_set_to, scene_not_found) {
	bs_frame_t *frame = bs_frame_create();
	bs_scene_t *scene_1 = bs_scene_create("1");
	bool status = false;

	bs_scene_add_to_frame(frame, scene_1);
	status = bs_scene_set_to(frame, "10");
	cr_assert(status == false);
	bs_frame_destroy(frame);
}

Test(bs_scene_set_to, frame_null) {
	bs_frame_t *frame = NULL;
	bool status = false;

	status = bs_scene_set_to(frame, "1");
	cr_assert(status == false);
}

Test(bs_scene_set_to, scene_null) {
	bs_frame_t *frame = bs_frame_create();
	bool status = false;

	status = bs_scene_set_to(frame, NULL);
	cr_assert(status == false);
	bs_frame_destroy(frame);
}
