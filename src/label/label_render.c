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
	if (frame == NULL || label == NULL || label->enabled == false)
		return (1);
	sfText_setFont(label->text, label->font);
	sfText_setPosition(label->text, label->pos);
	sfRenderWindow_drawText(frame->window, label->text, label->rs);
	return (1);
}
