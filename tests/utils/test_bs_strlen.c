/*
** EPITECH PROJECT, 2018
** Function: bs_strlen
** File description:
** Tests the function bs_strlen
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_strlen, basic_input) {
	char *str = "123456789";
	int length = 0;

	length = bs_strlen(str);
	cr_assert(length == 9);
}

Test(bs_strlen, null_input) {
	char *str = NULL;
	int length = 0;

	length = bs_strlen(str);
	cr_assert(length == 0);
}