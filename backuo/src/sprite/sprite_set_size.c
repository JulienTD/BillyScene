/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Sets the sprite's size
 * 
 * @param sprite 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool bs_sprite_set_size(bs_sprite_t *sprite, int x, int y)
{
	if (sprite == NULL)
		return (0);
	sprite->size.x = x;
	sprite->size.y = y;
	sprite->is_init = 0;
	return (1);
}