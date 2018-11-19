/*
** EPITECH PROJECT, 2018
** Function: bs_strcpy
** File description:
** Tests the function bs_strcpy
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_strcpy, basic_input) {
	char *src = "test";
	char *dest = malloc(5 * sizeof(char));

	dest = bs_strcpy(src, dest);
	cr_assert_str_eq(src, dest);
	free(dest);
}

Test(bs_strcpy, all_null_input) {
	char *src = NULL;
	char *dest = NULL;

	dest = bs_strcpy(src, dest);
	cr_assert(dest == NULL);
}
