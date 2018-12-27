/*
** EPITECH PROJECT, 2018
** Function: bs_label_create
** File description:
** Tests the function bs_label_create
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_label_create, basic) {
	bs_label_t *label = bs_label_create("test", \
	"./tests/res/font.ttf", "", 10);

	cr_assert_not_null(label); 
	cr_assert_not_null(label->font);
	cr_assert_not_null(label->id_label);
	cr_assert_str_eq(label->id_label, "test");
	cr_assert_not_null(label->rs);
	cr_assert_not_null(label->text);
}

Test(bs_label_create, null_font) {
	bs_label_t *label = bs_label_create("test", \
	NULL, "", 10);

	cr_assert_null(label);
}

Test(bs_label_create, null_id) {
	bs_label_t *label = bs_label_create(NULL, \
	"./tests/res/font.ttf", "", 10);

	cr_assert_null(label);
}

Test(bs_label_create, wrong_font_path) {
	bs_label_t *label = bs_label_create("test", \
	"./tests/wrongpath/font.ttf", "", 10);

	cr_assert_null(label);
}