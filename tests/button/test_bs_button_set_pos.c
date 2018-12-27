/*
** EPITECH PROJECT, 2018
** Function: bs_button_set_pos
** File description:
** Tests the function bs_button_set_pos
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_button_set_pos, basic) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bool status = false;
	float pos_x = 200;
	float pos_y = 300;

	cr_assert_not_null(button);
	status = bs_button_set_pos(button, pos_x, pos_y);
	cr_assert(status == true);
	cr_assert(button->pos.x == pos_x);
	cr_assert(button->pos.y == pos_y);
	bs_button_destroy(button);
}

Test(bs_button_set_pos, null_button) {
	bs_button_t *button = NULL;
	bool status = true;
	float pos_x = 200;
	float pos_y = 300;

	status = bs_button_set_pos(button, pos_x, pos_y);
	cr_assert(status == false);
}