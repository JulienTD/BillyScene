/*
** EPITECH PROJECT, 2018
** Function: bs_list_length
** File description:
** Tests the function bs_list_length
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_list_length, basic) {
	bs_list_t *list = NULL;

	bs_list_push(&(list), NULL);
	bs_list_push(&(list), NULL);
	bs_list_push(&(list), NULL);
	cr_assert(bs_list_length(&list) == 3);
}

Test(bs_list_length, head_null) {
	bs_list_t *list = NULL;

	cr_assert(bs_list_length(&list) == 0);
}
