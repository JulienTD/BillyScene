/*
** EPITECH PROJECT, 2018
** Function: bs_frame_create
** File description:
** Tests the function bs_frame_create
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_frame_create, basic) {
	bs_frame_t *frame = bs_frame_create();

	cr_assert_not_null(frame);
	cr_assert_null(frame->window);
	cr_assert_null(frame->clock);
	cr_assert_null(frame->current_scene);
	cr_assert_null(frame->last_scene);
	cr_assert_null(frame->scenes);
	cr_assert_null(frame->cursor);
	cr_assert_null(frame->data);
	cr_assert(frame->height == 0);
	cr_assert(frame->width == 0);
	cr_assert(frame->components_volume_level == 50);
	cr_assert(frame->max_tick == 20);
}
