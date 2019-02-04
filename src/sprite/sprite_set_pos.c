/*
** BillyScene, 2018
** sprite_set_pos
** File description:
** bs_sprite_set_pos
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Sets the sprite position
 * 
 * @param sprite
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool bs_sprite_set_pos(bs_sprite_t *sprite, float x, float y)
{
    if (sprite == NULL)
        return (0);
    sprite->pos.x = x;
    sprite->pos.y = y;
    sprite->is_init = false;
    return (1);
}