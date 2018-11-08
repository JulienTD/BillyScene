/*
** EPITECH PROJECT, 2018
** textfield_set_max_length
** File description:
** Sets textfield's max length
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Set textfield's max length
 * If max_length is negative then it will be considered as infinite
 * 
 * @param textfield
 * @param max_length 
 * @return true 
 * @return false 
 */
bool bs_textfield_set_max_length(bs_textfield_t *textfield, int max_length)
{
	if (textfield == NULL) {
		return (false);
	}
	textfield->max_length = max_length;
	return (true);
}
