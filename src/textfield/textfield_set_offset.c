/*
** EPITECH PROJECT, 2018
** label_set_pos
** File description:
** Sets the position of the label
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

bool bs_textfield_set_offset(bs_textfield_t *textfield, \
float offset_x, float offset_y)
{
	if (textfield == NULL) {
		return (false);
	}
	textfield->offset.x = offset_x;
	textfield->offset.y = offset_y;
	return (true);
}
