/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Plays animation
 * 
 * @param sprite 
 * @param id 
 * @param reverse 
 * @return bs_sprite_anim_t* 
 */
bs_sprite_anim_t *bs_sprite_anim_play(bs_sprite_t *sprite, char *id, \
bool reverse)
{
    bs_sprite_anim_t *anim = NULL;

    if (sprite == NULL || id == NULL) {
        return (NULL);
    }
    anim = bs_sprite_anim_get_by_id(sprite, id);
    if (anim == NULL) {
        return (NULL);
    }
    bs_sprite_anim_stop(sprite);
    anim->curr_state = 0;
    anim->curr_tick_delay = 0;
    anim->is_finish = false;
    anim->stay_now = false;
    anim->reverse = reverse;
    return (anim);
}
