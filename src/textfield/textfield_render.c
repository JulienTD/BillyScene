/*
** EPITECH PROJECT, 2018
** label_set_pos
** File description:
** Sets the position of the label
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

bool bs_textfield_render(bs_frame_t *frame, bs_textfield_t *textfield)
{
	sfRenderStates *states = NULL;

	if (frame == NULL || textfield == NULL || textfield->enabled == false)
		return (false);
	states = bs_init_render_states();
	if (states == NULL)
		return (1);
	if (textfield->texture)
		sfRectangleShape_setTexture(textfield->rect, \
		textfield->texture, sfFalse);
	sfRectangleShape_setPosition(textfield->rect, textfield->pos);
	bs_label_set_pos(textfield->label, textfield->pos.x, \
	textfield->pos.y);
	sfRenderWindow_drawRectangleShape(frame->window, textfield->rect, \
	states);
	bs_label_render(frame, textfield->label);
	free(states);
	return (true);
}