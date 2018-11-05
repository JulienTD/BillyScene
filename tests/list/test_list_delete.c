/*
** EPITECH PROJECT, 2018
** Function: bs_list_delete
** File description:
** Tests the function bs_list_delete
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_list_delete_element, first_element) {
	bs_list_t *list = NULL;
	int *nbr = malloc(sizeof(int));

	if (nbr == NULL)
		return;
	*nbr = 9;
	bs_list_push(&list, NULL);
	bs_list_push(&list, nbr);
	bs_list_push(&list, NULL);
	bs_list_delete(&list, 0);
	cr_assert(*(int *)(list->data) == 9);
}

Test(bs_list_delete_element, middle_element) {
	bs_list_t *list = NULL;
	int *nbr = malloc(sizeof(int));

	if (nbr == NULL)
		return;
	*nbr = 9;
	bs_list_push(&list, NULL);
	bs_list_push(&list, NULL);
	bs_list_push(&list, nbr);
	bs_list_delete(&list, 1);
	cr_assert(*(int *)(list->next->data) == 9);
}

Test(bs_list_delete_element, last_element) {
	bs_list_t *list = NULL;
	int *nbr = malloc(sizeof(int));

	if (nbr == NULL)
		return;
	bs_list_push(&list, NULL);
	bs_list_push(&list, NULL);
	bs_list_push(&list, NULL);
	bs_list_delete(&list, 2);
	cr_assert(bs_list_length(&list) == 2);
}