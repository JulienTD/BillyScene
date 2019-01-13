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

static bool determine_button_position(bs_button_t *button)
{
	sfVector2f new_pos = {.x = 0, .y = 0};

	if (button == NULL)
		return (false);
	new_pos.x = button->pos.x + button->offset.x;
	new_pos.y = button->pos.y + button->offset.y;
	sfRectangleShape_setPosition(button->rect, new_pos);
	return (true);
}

/**
 * @brief Renders a button
 * 
 * @param frame 
 * @param button 
 * @return int 
 */
bool bs_button_render(bs_frame_t *frame, bs_button_t *button)
{
	if (frame == NULL || button == NULL || button->enabled == false)
		return (false);
	if (button->status == NORMAL && button->texture_base != NULL) {
		sfRectangleShape_setTexture(button->rect,
		button->texture_base, sfFalse);
	} else if (button->status == CLICKED && \
	button->texture_hover != NULL) {
		sfRectangleShape_setTexture(button->rect,
		button->texture_hover, sfFalse);
	} else {
		if (button->texture_clicked != NULL)
			sfRectangleShape_setTexture(button->rect, \
			button->texture_clicked, sfFalse);
	}
	determine_button_position(button);
	sfRenderWindow_drawRectangleShape(frame->window, button->rect, \
	button->rs);
	return (true);
}
