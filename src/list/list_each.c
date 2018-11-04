/*
** EPITECH PROJECT, 2017
** scene_manager
** File description:
** scene_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

bool bs_list_each(bs_list_t **head, bool (*func_each)(void *data))
{
	bs_list_t *curr = NULL;

	if (head == NULL || *head == NULL || func_each == NULL) {
		return (false);
	}
	curr = *head;
	while (curr) {
		if (func_each != NULL) {
			func_each(curr->data);
		}
		curr = curr->next;
	}
	return (true);
}
