/*
** EPITECH PROJECT, 2018
** Function: bs_button_set_sound_hover_out
** File description:
** Tests the function bs_button_set_sound_hover_out
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_button_set_sound_hover_out, basic) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bool status = false;

	cr_assert_not_null(button);
	status = bs_button_set_sound_hover_out(button, \
	"./tests/res/sound.ogg");
	cr_assert(status == true);
	bs_button_destroy(button);
}

Test(bs_button_set_sound_hover_out, null_button) {
	bs_button_t *button = NULL;
	bool status = true;

	status = bs_button_set_sound_hover_out(button, \
	"./tests/res/sound.ogg");
	cr_assert(status == false);
}

Test(bs_button_set_sound_hover_out, wrong_path) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bool status = true;

	cr_assert_not_null(button);
	status = bs_button_set_sound_hover_out(button, \
	"./tests/res/wrong_path");
	cr_assert(status == false);
	bs_button_destroy(button);
}
