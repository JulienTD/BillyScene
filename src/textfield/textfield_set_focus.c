 /*
** EPITECH PROJECT, 2018
** label_set_pos
** File description:
** Sets the position of the label
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

bool bs_textfield_set_focus(bs_textfield_t *textfield, bool is_focus)
{
	if (textfield == NULL) {
		return (false);
	}
	textfield->is_focus = is_focus;
	return (true);
}
