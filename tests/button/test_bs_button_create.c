/*
** EPITECH PROJECT, 2018
** Function: bs_button_create
** File description:
** Tests the function bs_button_create
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_button_create, basic) {
	bs_button_t *button = bs_button_create("test", 100, 100);

	cr_assert_not_null(button);
	cr_assert_not_null(button->id_button);
	cr_assert_str_eq(button->id_button, "test");
	cr_assert_not_null(button->rect);
	cr_assert_null(button->texture_base);
	cr_assert_null(button->texture_hover);
	cr_assert_null(button->texture_clicked);
	cr_assert_null(button->sound_click);
	cr_assert_null(button->sound_hover_in);
	cr_assert_null(button->sound_hover_out);
	cr_assert_null(button->click_pressed_event);
	cr_assert_null(button->click_released_event);
	cr_assert_null(button->hover_event);
	cr_assert_null(button->hover_in_event);
	cr_assert_null(button->hover_out_event);
	cr_assert_not_null(button->rs);
	cr_assert(button->status == NORMAL);
}
