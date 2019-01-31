/*
** BillyScene, 2018
** sprite_anim_get_default
** File description:
** bs_sprite_anim_get_default
*/

#include <stdbool.h>
#include "bs_components.h"
#include "bs_prototypes.h"

bs_sprite_anim_t *bs_sprite_anim_get_default(bs_sprite_t *sprite)
{
    bs_sprite_anim_t *anim = NULL;
    bs_list_t *curr = NULL;

    if (sprite == NULL) {
        return (NULL);
    }
    curr = sprite->anims;
    while (curr) {
        anim = (bs_sprite_anim_t *)curr->data;
        if (anim->is_default == true) {
            return (anim);
        }
        curr = curr->next;
    }
    return (NULL);
}
