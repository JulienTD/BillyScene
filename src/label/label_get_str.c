/*
** EPITECH PROJECT, 2018
** label_set_pos
** File description:
** Sets the position of the label
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Gets label str
 * 
 * @param label 
 * @param str 
 * @return true 
 * @return false 
 */
const char *bs_label_get_str(bs_label_t *label)
{
	if (label == NULL) {
		return (NULL);
	}
	return sfText_getString(label->text);
}
