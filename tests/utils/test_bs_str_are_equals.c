/*
** EPITECH PROJECT, 2018
** Function: bs_str_are_equals
** File description:
** Tests the function bs_str_are_equals
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_str_are_equals, basic_input_equal) {
	char *str = "test";
	char *str2 = "test";

	cr_assert(bs_str_are_equals(str, str2) == true);
}

Test(bs_str_are_equals, basic_input_not_equal) {
	char *str = "test";
	char *str2 = "test2";

	cr_assert(bs_str_are_equals(str, str2) == false);
}

Test(bs_str_are_equals, basic_input_not_equal2) {
	char *str = "test";
	char *str2 = "tes,";

	cr_assert(bs_str_are_equals(str, str2) == false);
}

Test(bs_str_are_equals, all_null_input) {
	char *str = NULL;
	char *str2 = NULL;

	cr_assert(bs_str_are_equals(str, str2) == true);
}

Test(bs_str_are_equals, one_null) {
	char *str = "test";
	char *str2 = NULL;

	cr_assert(bs_str_are_equals(str, str2) == false);
}
