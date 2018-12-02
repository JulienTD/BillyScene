/*
** EPITECH PROJECT, 2018
** Function: bs_button_hitbox
** File description:
** Tests the function bs_button_hitbox
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_button_hitbox, basic) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bool status = false;

	cr_assert_not_null(button);
	bs_button_set_pos(button, 100, 100);
	status = bs_is_mouse_on_button(*button, 100, 100);
	cr_assert(status == true);
	bs_button_destroy(button);
}

Test(bs_button_hitbox, not_in_range) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bool status = false;

	cr_assert_not_null(button);
	bs_button_set_pos(button, 100, 100);
	status = bs_is_mouse_on_button(*button, 99, 99);
	cr_assert(status == false);
	bs_button_destroy(button);
}