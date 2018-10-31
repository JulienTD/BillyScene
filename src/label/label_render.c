/*
** EPITECH PROJECT, 2018
** texts_manager
** File description:
** texts_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

int bs_label_render(bs_frame_t *frame, bs_label_t *label)
{
	sfRenderStates *states = NULL;

	if (frame == NULL || label == NULL || label->enabled == false)
		return (1);
	states = bs_init_render_states();
	if (states == NULL)
		return (0);
	sfText_setFont(label->text, label->font);
	sfRenderWindow_drawText(frame->window, label->text, states);
	free(states);
	return (1);
}
