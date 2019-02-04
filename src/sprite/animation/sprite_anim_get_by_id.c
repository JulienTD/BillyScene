/*
** BillyScene, 2018
** sprite_anim_get_by_id
** File description:
** bs_sprite_anim_get_by_id
*/

#include <stdbool.h>
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Gets animation by its id
 * 
 * @param sprite
 * @param id
 * @return bs_sprite_anim_t*
 */
bs_sprite_anim_t *bs_sprite_anim_get_by_id(bs_sprite_t *sprite, char *id)
{
    bs_sprite_anim_t *anim = NULL;
    bs_list_t *curr = NULL;

    if (sprite == NULL) {
        return (NULL);
    }
    curr = sprite->anims;
    while (curr) {
        anim = (bs_sprite_anim_t *)curr->data;
        if (bs_str_are_equals(anim->id_anim, id)) {
            return (anim);
        }
        curr = curr->next;
    }
    return (NULL);
}
