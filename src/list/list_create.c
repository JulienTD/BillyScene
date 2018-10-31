/*
** EPITECH PROJECT, 2018
** create_list
** File description:
** create_list
*/

#include "bs_components.h"
#include "bs_prototypes.h"

bs_list_t *bs_list_create(void *data)
{
	bs_list_t *element = malloc(sizeof(bs_list_t));

	if (element == NULL)
		return (NULL);
	element->id = 0;
	element->data = data;
	element->next = NULL;
	return element;
}
