/*
** BillyScene, 2018
** sprite_anim_get_active
** File description:
** bs_sprite_anim_get_active
*/

#include <stdbool.h>
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Returns active animation on sprite
 * 
 * @param sprite
 */
bs_sprite_anim_t *bs_sprite_anim_get_active(bs_sprite_t *sprite)
{
    bs_sprite_anim_t *anim = NULL;
    bs_list_t *curr = NULL;

    if (sprite == NULL) {
        return (NULL);
    }
    curr = sprite->anims;
    while (curr) {
        anim = (bs_sprite_anim_t *)curr->data;
        if (anim->is_finish == false) {
            return (anim);
        }
        curr = curr->next;
    }
    return (NULL);
}
