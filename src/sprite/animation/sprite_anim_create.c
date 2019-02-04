/*
** BillyScene, 2018
** sprite_anim_create
** File description:
** bs_sprite_anim_create
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

static bool set_default_params(bs_sprite_anim_t *anim)
{
    anim->is_default = false;
    anim->is_finish = true;
    anim->is_looped = false;
    anim->is_vertical = false;
    anim->max_states = 0;
    anim->max_tick_delay = 0;
    anim->curr_state = 0;
    anim->curr_tick_delay = 0;
    return (true);
}

/**
 * @brief Creates new animation
 * 
 * @param id
 * @param path
 * @param height
 * @param width
 * @return bs_sprite_anim_t*
 */
bs_sprite_anim_t *bs_sprite_anim_create(char *id, char *path, \
float height, float width)
{
    bs_sprite_anim_t *anim = malloc(sizeof(bs_sprite_anim_t));
    sfVector2f pos = {.x = 0, .y = 0};
    sfVector2f size = {.x = width, .y = height};

    if (anim == NULL)
        return NULL;
    anim->id_anim = NULL;
    anim->id_anim = bs_set_str_to(anim->id_anim, id);
    set_default_params(anim);
    anim->pos_s = pos;
    anim->pos_a = pos;
    anim->reverse = false;
    anim->size = size;
    anim->sprite = sfSprite_create();
    anim->stay_now = false;
    anim->stay_on_last_frame = false;
    anim->texture = sfTexture_createFromFile(path, NULL);
    anim->rs = bs_init_render_states();
    return (anim);
}
