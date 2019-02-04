/*
** BillyScene, 2019
** sprite_set_layer
** File description:
** Sets the sprite's layer
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the sprite's layer
 *
 * @param button
 * @return true
 * @return false
 */
bool bs_sprite_set_layer(bs_sprite_t *sprite, short layer)
{
    if (sprite == NULL)
        return (false);
    sprite->layer = layer;
    return (true);
}
