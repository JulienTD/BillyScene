/*
** EPITECH PROJECT, 2018
** Function: bs_button_render
** File description:
** Tests the function bs_button_render
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_button_render, basic) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bs_frame_t *frame = bs_frame_create();
	sfVideoMode mode = {100, 100, 32};
	bool status = false;

	cr_assert_not_null(frame);
	frame->window = sfRenderWindow_create(mode, "Billy Scene", \
	sfClose, NULL);
	status = bs_button_render(frame, button);
	cr_assert(status == true);
}

Test(bs_button_render, null_button) {
	bs_frame_t *frame = bs_frame_create();
	sfVideoMode mode = {100, 100, 32};
	bool status = false;

	cr_assert_not_null(frame);
	frame->window = sfRenderWindow_create(mode, "Billy Scene", \
	sfClose, NULL);
	status = bs_button_render(frame, NULL);
	cr_assert(status == false);
	bs_frame_destroy(frame);
}

Test(bs_button_render, null_frame) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bool status = false;

	cr_assert_not_null(button);
	status = bs_button_render(NULL, button);
	cr_assert(status == false);
	bs_button_destroy(button);
}
