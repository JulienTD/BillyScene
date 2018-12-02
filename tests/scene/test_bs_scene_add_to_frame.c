/*
** EPITECH PROJECT, 2018
** Function: bs_scene_add_to_frame
** File description:
** Tests the function bs_scene_add_to_frame
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_scene_add_to_frame, basic) {
	bs_frame_t *frame = bs_frame_create();
	bs_scene_t *scene_1 = bs_scene_create("1");
	bool status = false;

	status = bs_scene_add_to_frame(frame, scene_1);
	cr_assert(status == true);
	bs_frame_destroy(frame);
}

Test(bs_scene_add_to_frame, frame_null) {
	bs_frame_t *frame = NULL;
	bs_scene_t *scene_1 = bs_scene_create("1");
	bool status = false;

	status = bs_scene_add_to_frame(frame, scene_1);
	cr_assert(status == false);
	bs_scene_destroy(scene_1);
}

Test(bs_scene_add_to_frame, scene_null) {
	bs_frame_t *frame = bs_frame_create();
	bs_scene_t *scene_1 = NULL;
	bool status = false;

	status = bs_scene_add_to_frame(frame, scene_1);
	cr_assert(status == false);
	bs_frame_destroy(frame);
}