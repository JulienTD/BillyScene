/*
** EPITECH PROJECT, 2018
** get_list_by_id
** File description:
** get_list_by_id
*/

#include "bs_components.h"
#include "bs_prototypes.h"

bs_list_t *bs_list_get_element(bs_list_t **head, int id)
{
	bs_list_t *curr = NULL;

	if (head == NULL)
		return NULL;
	curr = *head;
	while (curr) {
		if (curr->id == id) {
			return curr;
		}
		curr = curr->next;
	}
	return (NULL);
}