/*
** EPITECH PROJECT, 2018
** Function: bs_scene_get_by_id
** File description:
** Tests the function bs_scene_get_by_id
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_scene_get_by_id, basic) {
	bs_frame_t *frame = bs_frame_create();
	bs_scene_t *scene_1 = bs_scene_create("1");
	bs_scene_t *scene_2 = bs_scene_create("2");
	bs_scene_t *scene_3 = bs_scene_create("3");
	bs_scene_t *tmp = NULL;

	bs_scene_add_to_frame(frame, scene_1);
	bs_scene_add_to_frame(frame, scene_2);
	bs_scene_add_to_frame(frame, scene_3);
	tmp = bs_scene_get_by_id(frame, "2");
	cr_assert_not_null(tmp);
	cr_assert_str_eq(tmp->id_scene, "2");
	bs_frame_destroy(frame);
}

Test(bs_scene_get_by_id, frame_null) {
	bs_frame_t *frame = NULL;
	bs_scene_t *tmp = NULL;

	tmp = bs_scene_get_by_id(frame, "2");
	cr_assert_null(tmp);
}

Test(bs_scene_get_by_id, id_null) {
	bs_frame_t *frame = bs_frame_create();
	bs_scene_t *tmp = NULL;

	tmp = bs_scene_get_by_id(frame, NULL);
	cr_assert_null(tmp);
}

Test(bs_scene_get_by_id, id_not_found) {
	bs_frame_t *frame = bs_frame_create();
	bs_scene_t *scene_1 = bs_scene_create("1");
	bs_scene_t *scene_2 = bs_scene_create("2");
	bs_scene_t *scene_3 = bs_scene_create("3");
	bs_scene_t *tmp = NULL;

	bs_scene_add_to_frame(frame, scene_1);
	bs_scene_add_to_frame(frame, scene_2);
	bs_scene_add_to_frame(frame, scene_3);
	tmp = bs_scene_get_by_id(frame, "10");
	cr_assert_null(tmp);
}
