/*
** BillyScene, 2018
** sprite_anim_add
** File description:
** bs_sprite_anim_add
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Adds animation to sprite
 * 
 * @param sprite
 * @param anim
 * @return true
 * @return false
 */
bool bs_sprite_anim_add(bs_sprite_t *sprite, bs_sprite_anim_t *anim)
{
    if (sprite == NULL || anim == NULL)
        return false;
    return bs_list_push(&(sprite->anims), anim, BS_SPRITE_ANIM) != NULL;
}
