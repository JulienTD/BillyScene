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
void bs_list_destroy(bs_list_t **head, void (*destroy)(void *data))
{
	bs_list_t *curr = NULL;
	bs_list_t *tmp = NULL;

	if (head == NULL || *head == NULL)
		return;
	curr = *head;
	while (curr) {
		if (destroy != NULL) {
			destroy(curr->data);
			curr->data = NULL;
		}
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	*head = NULL;
}