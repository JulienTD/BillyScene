/*
** EPITECH PROJECT, 2018
** Function: bs_list_get_by_id
** File description:
** Tests the function bs_list_get_by_id
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_list_get_by_id, head_null) {
	bs_list_t *list = NULL;

	cr_assert(bs_list_get_by_id(&list, 10) == NULL);
}

Test(bs_list_get_by_id, basic) {
	bs_list_t *list = NULL;
	bs_list_t *requested_list = NULL;

	bs_list_push(&list, NULL, BS_UNKNOW);
	bs_list_push(&list, NULL, BS_UNKNOW);
	bs_list_push(&list, NULL, BS_UNKNOW);
	requested_list = bs_list_get_by_id(&list, 1);
	cr_assert(requested_list != NULL);
	cr_assert(requested_list->id == 1);
}

Test(bs_list_get_by_id, out_of_range) {
	bs_list_t *list = NULL;
	bs_list_t *requested_list = NULL;

	bs_list_push(&list, NULL, BS_UNKNOW);
	bs_list_push(&list, NULL, BS_UNKNOW);
	bs_list_push(&list, NULL, BS_UNKNOW);
	requested_list = bs_list_get_by_id(&list, 99);
	cr_assert(requested_list == NULL);
}
