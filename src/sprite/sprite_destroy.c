/*
** BillyScene, 2018
** sprite_destroy
** File description:
** bs_sprite_destroy
*/

#include "bs_components.h"
#include "bs_prototypes.h"

static void destroy_anim(bs_list_t *list)
{
    bs_sprite_anim_destroy(list->data);
}

/**
 * @brief Destroys sprite
 * 
 * @param sprite
 */
void bs_sprite_destroy(bs_sprite_t *sprite)
{
    if (sprite == NULL)
        return;
    bs_list_destroy(&sprite->anims, &destroy_anim);
    if (sprite->curr_anim)
        free(sprite->curr_anim);
    if (sprite->id_sprite)
        free(sprite->id_sprite);
    if (sprite->sprite)
        sfSprite_destroy(sprite->sprite);
    if (sprite->texture)
        sfTexture_destroy(sprite->texture);
    if (sprite->rs)
        free(sprite->rs);
    free(sprite);
}