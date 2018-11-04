/*
** EPITECH PROJECT, 2018
** get_list_length
** File description:
** get_list_length
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Returns the list length
 * 
 * @param head 
 * @return int 
 */
int bs_list_length(bs_list_t **head)
{
	bs_list_t *curr = NULL;
	int length = 0;

	if (head == NULL || *head == NULL)
		return (0);
	curr = *head;
	while (curr) {
		length++;
		curr = curr->next;
	}
	return (length);
}