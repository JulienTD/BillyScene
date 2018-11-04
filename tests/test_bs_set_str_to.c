/*
** EPITECH PROJECT, 2018
** Function: bs_set_str_to
** File description:
** Tests the function bs_set_str_to
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_set_str_to, init_null) {
	char *str = NULL;

	str = bs_set_str_to(str, "New str");
	cr_assert_str_eq(str, "New str");
}

Test(bs_set_str_to, wrong_input) {
	char *str = malloc(2 * sizeof(char));

	if (str == NULL)
		return;
	str[0] = 'A';
	str[1] = '\0';
	str = bs_set_str_to(str, "New str");
	cr_assert_str_eq(str, "New str");
	free(str);
}