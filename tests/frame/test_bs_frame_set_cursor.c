/*
** EPITECH PROJECT, 2018
** Function: bs_frame_set_cursor
** File description:
** Tests the function bs_frame_set_cursor
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_frame_set_cursor, null_window) {
	bs_frame_t *frame = bs_frame_create();
	bool status = true;

	cr_assert_not_null(frame);
	status = bs_frame_set_cursor(frame, "./tests/res/texture.png");
	cr_assert(status == false);
	cr_assert_null(frame->cursor);
	bs_frame_destroy(frame);
}

Test(bs_frame_set_cursor, null_frame) {
	bs_frame_t *frame = NULL;
	bool status = true;

	status = bs_frame_set_cursor(frame, "./tests/res/texture.png");
	cr_assert(status == false);
}

Test(bs_frame_set_cursor, basic) {
	bs_frame_t *frame = bs_frame_create();
	sfVideoMode mode = {100, 100, 32};

	cr_assert_not_null(frame);
	frame->window = sfRenderWindow_create(mode, "Billy Scene", \
	sfClose, NULL);
	cr_assert_not_null(frame);
	bs_frame_set_cursor(frame, "./tests/res/texture.png");
	cr_assert_not_null(frame->cursor);
	bs_frame_destroy(frame);
}