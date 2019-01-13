/*
** EPITECH PROJECT, 2018
** Function: bs_list_each
** File description:
** Tests the function bs_list_each
*/

#include <stdarg.h>
#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

/*
	TODO: make it works
*/

bool id_increment(bs_list_t *element, va_list *args);
bool check_id(bs_list_t *element, va_list *args);

Test(bs_list_each, head_null_func_null) {
	bs_list_t *list = NULL;

	cr_assert(bs_list_each(&list, NULL) == false);
}

Test(bs_list_each, head_not_null_func_not_null) {
	bs_list_t *list = NULL;
	int *nbr_1 = malloc(sizeof(int));
	int *nbr_2 = NULL;

	if (nbr_1 == NULL)
		return;
	nbr_2 = malloc(sizeof(int));
	if (nbr_2 == NULL)
		return;
	*nbr_1 = 0;
	*nbr_2 = 1;
	bs_list_push(&list, nbr_1, BS_UNKNOW);
	bs_list_push(&list, nbr_2, BS_UNKNOW);
	cr_assert(bs_list_each(&list, &id_increment) == true);
	cr_assert(*nbr_1 == 1);
	cr_assert(*nbr_2 == 2);
}

Test(bs_list_each, check_infinite_args) {
	bs_list_t *list = NULL;
	int *nbr_1 = malloc(sizeof(int));
	int *nbr_2 = NULL;

	if (nbr_1 == NULL)
		return;
	nbr_2 = malloc(sizeof(int));
	if (nbr_2 == NULL)
		return;
	*nbr_1 = 0;
	*nbr_2 = 1;
	bs_list_push(&list, nbr_1, BS_UNKNOW);
	bs_list_push(&list, nbr_2, BS_UNKNOW);
	cr_assert(bs_list_each(&list, &check_id, nbr_1) == true);
	cr_assert(*nbr_1 == 2);
}

Test(bs_list_each, head_not_null_func_null) {
	bs_list_t *list = NULL;
	int *nbr_1 = malloc(sizeof(int));
	int *nbr_2 = NULL;

	if (nbr_1 == NULL)
		return;
	nbr_2 = malloc(sizeof(int));
	if (nbr_2 == NULL)
		return;
	*nbr_1 = 0;
	*nbr_2 = 1;
	bs_list_push(&list, nbr_1, BS_UNKNOW);
	bs_list_push(&list, nbr_2, BS_UNKNOW);
	cr_assert(bs_list_each(&list, NULL) == false);
}

bool id_increment(bs_list_t *element, va_list *args \
__attribute__((__unused__)))
{
	int *nbr = element->data;

	(*nbr)++;
	return (true);
}

bool check_id(bs_list_t *element, va_list *args)
{
	int *nbr = (int *)va_arg(*args, void *);

	(*nbr)++;
	return (true);
}
