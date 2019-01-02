/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Sets the sprite offset
 * 
 * @param sprite 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool bs_sprite_set_offset(bs_sprite_t *sprite, float offset_x, float offset_y)
{
	if (sprite == NULL)
		return (0);
	sprite->offset.x = offset_x;
	sprite->offset.y = offset_y;
	sprite->is_init = false;
	return (1);
}
