/*
** EPITECH PROJECT, 2018
** Function: bs_list_get_element
** File description:
** Tests the function bs_list_get_element
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_list_get_element, head_null) {
	bs_list_t *list = NULL;

	cr_assert(bs_list_get_element(&list, 10) == NULL);
}

Test(bs_list_get_element, basic) {
	bs_list_t *list = NULL;
	bs_list_t *requested_list = NULL;

	bs_list_push(&list, NULL);
	bs_list_push(&list, NULL);
	bs_list_push(&list, NULL);
	requested_list = bs_list_get_element(&list, 1);
	cr_assert(requested_list != NULL);
	cr_assert(requested_list->id == 1);
}

Test(bs_list_get_element, out_of_range) {
	bs_list_t *list = NULL;
	bs_list_t *requested_list = NULL;

	bs_list_push(&list, NULL);
	bs_list_push(&list, NULL);
	bs_list_push(&list, NULL);
	requested_list = bs_list_get_element(&list, 99);
	cr_assert(requested_list == NULL);
}
