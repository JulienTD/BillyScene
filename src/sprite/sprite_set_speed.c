/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Sets the sprite's speed
 * 
 * @param sprite 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool bs_sprite_set_speed(bs_sprite_t *sprite, float x, float y)
{
    if (sprite == NULL)
        return (0);
    sprite->speed.x = x;
    sprite->speed.y = y;
    return (1);
}