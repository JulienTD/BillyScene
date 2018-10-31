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
 * @brief Sets the label's position
 * 
 * @param label 
 * @param pos_x 
 * @param pos_y 
 * @return true 
 * @return false 
 */
bool bs_label_set_pos(bs_label_t *label, float pos_x, float pos_y)
{
	if (label == NULL)
		return (false);
	sfText_setPosition(label->text, pos_x, pos_y);
	return (true);
}