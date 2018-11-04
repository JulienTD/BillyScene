/*
** EPITECH PROJECT, 2018
** Function: bs_list_create
** File description:
** Tests the function bs_list_create
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_list_create, basic) {
	int *nbr = malloc(sizeof(int));
	bs_list_t *list = NULL;

	if (nbr == NULL)
		return;
	*nbr = 9;
	list = bs_list_create(nbr);
	cr_assert(list != NULL);
	cr_assert(list->data != NULL);
	cr_assert(*(int *)(list->data) == 9);
}

Test(bs_list_create, data_null) {
	bs_list_t *list = bs_list_create(NULL);

	cr_assert(list != NULL);
	cr_assert(list->data == NULL);
}
