/*
** EPITECH PROJECT, 2018
** get_list_by_id
** File description:
** get_list_by_id
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Destroys a list with a custom function to destroy the data
 * 
 * @param head 
 * @param destroy 
 * @return true 
 * @return false 
 */
bool bs_list_destroy(bs_list_t **head, bool (*destroy)(void *data))
{
	bs_list_t *curr = NULL;
	bs_list_t *tmp = NULL;

	if (head == NULL)
		return (true);
	curr = *head;
	while (curr) {
		if (destroy != NULL) {
			destroy(curr->data);
		}
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	return (true);
}