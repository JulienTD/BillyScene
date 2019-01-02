/*
** EPITECH PROJECT, 2018
** label_set_pos
** File description:
** Sets the position of the label
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

bool bs_textfield_set_pos(bs_textfield_t *textfield, float pos_x, float pos_y)
{
	if (textfield == NULL) {
		return (false);
	}
	textfield->pos.x = pos_x;
	textfield->pos.y = pos_y;
	return (true);
}
