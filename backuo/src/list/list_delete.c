/*
** EPITECH PROJECT, 2018
** list_delete
** File description:
** list_delete
*/

#include "bs_components.h"
#include "bs_prototypes.h"

static bool delete_first_element(bs_list_t **head)
{
	if (head == NULL || *head == NULL)
		return true;
	*head = (*head)->next;
	return true;
}

bool bs_list_delete_element(bs_list_t **head, int id)
{
	bs_list_t *curr = NULL;
	bs_list_t *before_curr = NULL;

	if (id == 0) {
		delete_first_element(head);
		return true;
	}
	curr = bs_list_get_element(head, id);
	before_curr = bs_list_get_element(head, id - 1);
	if (curr == NULL || before_curr == NULL)
		return true;
	before_curr->next = curr->next;
	return true;
}