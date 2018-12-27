/*
** EPITECH PROJECT, 2018
** Function: bs_button_set_size
** File description:
** Tests the function bs_button_set_size
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_button_set_size, basic) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bool status = false;
	float width = 1000;
	float height = 500;
	sfVector2f curr_size;

	cr_assert_not_null(button);
	status = bs_button_set_size(button, width, height);
	curr_size = sfRectangleShape_getSize(button->rect);
	cr_assert(status == true);
	cr_assert(curr_size.x == width);
	cr_assert(curr_size.y == height);
	bs_button_destroy(button);
}

Test(bs_button_set_size, null_button) {
	bs_button_t *button = NULL;
	bool status = true;
	float width = 1000;
	float height = 500;

	status = bs_button_set_size(button, width, height);
	cr_assert(status == false);
}
