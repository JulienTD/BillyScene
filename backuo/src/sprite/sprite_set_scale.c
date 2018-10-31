/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Sets the sprite_scale
 * 
 * @param sprite 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool bs_sprite_set_scale(bs_sprite_t *sprite, float x, float y)
{
	if (sprite == NULL)
		return (0);
	sprite->scale.x = x;
	sprite->scale.y = y;
	return (1);
}