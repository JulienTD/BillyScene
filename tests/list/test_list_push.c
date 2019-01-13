/*
** EPITECH PROJECT, 2018
** Function: bs_list_push
** File description:
** Tests the function bs_list_push
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_list_push, head_null) {
	bs_list_t *head = NULL;
	int *nbr = malloc(sizeof(int));

	if (nbr == NULL)
		return;
	cr_assert(bs_list_push(&(head), nbr, BS_UNKNOW) != NULL);
	cr_assert(head != NULL);
	cr_assert(head->id == 0);
}

Test(bs_list_push, head_not_null) {
	bs_list_t *head = malloc(sizeof(bs_list_t));
	int *nbr = NULL;

	if (head == NULL)
		return;
	nbr = malloc(sizeof(int));
	if (nbr == NULL)
		return;
	head->next = NULL;
	head->data = NULL;
	head->id = 0;
	cr_assert(bs_list_push(&(head), nbr, BS_UNKNOW) != NULL);
	cr_assert(head->next != NULL);
	cr_assert(head->next->id == 1);
}
