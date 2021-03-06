/*
** BillyScene, 2018
** sprite_anim_stop
** File description:
** bs_sprite_anim_stop
*/

#include <stdbool.h>
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Stops current animation
 * 
 * @param sprite
 * @return true
 * @return false
 */
bool bs_sprite_anim_stop(bs_sprite_t *sprite)
{
    bs_list_t *curr = NULL;
    bs_sprite_anim_t *anim = NULL;

    if (sprite == NULL) {
        return (false);
    }
    while (curr) {
        anim = (bs_sprite_anim_t *)curr->data;
        anim->is_finish = true;
        anim->curr_state = 0;
        anim->curr_tick_delay = 0;
        anim->is_finish = true;
        anim->stay_now = false;
        curr = curr->next;
    }
    return (true);
}
