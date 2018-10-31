/*
** EPITECH PROJECT, 2018
** button_create
** File description:
** function to create a button structure
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Inits button textures
 * 
 * @param button 
 * @return true 
 * @return false 
 */
static bool inits_button_textures(bs_button_t *button)
{
	button->texture_base = NULL;
	button->texture_hover = NULL;
	button->texture_clicked = NULL;
	return true;
}

/**
 * @brief Inits button sounds
 * 
 * @param button 
 * @return true 
 * @return false 
 */
static bool inits_button_sounds(bs_button_t *button)
{
	button->sound_click = NULL;
	button->sound_hover_in = NULL;
	button->sound_hover_out = NULL;
	return true;
}

/**
 * @brief Inits button events
 * 
 * @param button 
 * @return true 
 * @return false 
 */
static bool inits_button_events(bs_button_t *button)
{
	button->click_pressed_event = NULL;
	button->click_released_event = NULL;
	button->hover_event = NULL;
	button->hover_in_event = NULL;
	button->hover_out_event = NULL;
	return true;
}

/**
 * @brief Creates a button from an id  and a size
 *
 * @param pos_x
 * @param pos_y
 * @param width
 * @param heigth
 * @return bs_button_t
 */
bs_button_t *bs_button_create(char *id, float width, float heigth)
{
	bs_button_t *button = malloc(sizeof(bs_button_t));

	if (button == NULL)
		return (NULL);
	button->rect = sfRectangleShape_create();
	if (button->rect == NULL)
		return NULL;
	bs_button_set_size(button, width, heigth);
	bs_button_set_pos(button, 0, 0);
	inits_button_events(button);
	inits_button_sounds(button);
	inits_button_textures(button);
	button->pos.x = 0;
	button->pos.y = 0;
	button->id_button = NULL;
	button->id_button = bs_set_str_to(button->id_button, id);
	button->status = NORMAL;
	button->texture_status = 0;
	button->enabled = true;
	return (button);
}
