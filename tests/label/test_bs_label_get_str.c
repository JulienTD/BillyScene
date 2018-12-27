/*
** EPITECH PROJECT, 2018
** Function: bs_label_get_str
** File description:
** Tests the function bs_label_get_str
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_label_get_str, basic) {
	bs_label_t *label = bs_label_create("test", \
	"./tests/res/font.ttf", "my label", 10);

	cr_assert_not_null(label);
	cr_assert_str_eq(bs_label_get_str(label), "my label");
	bs_label_destroy(label);
}
