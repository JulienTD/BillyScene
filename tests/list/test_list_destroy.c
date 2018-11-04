/*
** EPITECH PROJECT, 2018
** Function: bs_list_length
** File description:
** Tests the function bs_list_length
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_list_destroy, basic) {
	bs_list_t *list = NULL;
	char *str = malloc(2 * sizeof(char));

	if (str == NULL)
		return;
	str[0] = 'A';
	str[1] = '\0';
	bs_list_push(&(list), str);
	bs_list_push(&(list), NULL);
	bs_list_destroy(&(list), NULL);
	cr_assert(list == NULL);
	cr_assert(str == NULL);
}
