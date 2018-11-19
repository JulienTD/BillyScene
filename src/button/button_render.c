/*
** EPITECH PROJECT, 2018
** button_render
** File description:
** button_render
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Renders a button
 * 
 * @param frame 
 * @param button 
 * @return int 
 */
int bs_button_render(bs_frame_t *frame, bs_button_t *button)
{
	if (frame == NULL || button == NULL || button->enabled == false)
		return (1);
	if (button->status == NORMAL && button->texture_base != NULL) {
		sfRectangleShape_setTexture(button->rect,
		button->texture_base, sfFalse);
	} else if (button->status == CLICKED && \
	button->texture_hover != NULL) {
		sfRectangleShape_setTexture(button->rect,
		button->texture_hover, sfFalse);
	} else {
		if (button->texture_clicked != NULL)
			sfRectangleShape_setTexture(button->rect,
			button->texture_clicked, sfFalse);
	}
	sfRectangleShape_setPosition(button->rect, button->pos);
	sfRenderWindow_drawRectangleShape(frame->window, button->rect, \
	button->rs);
	return (0);
}