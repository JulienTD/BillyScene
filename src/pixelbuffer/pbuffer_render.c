/*
** EPITECH PROJECT, 2018
** texts_manager
** File description:
** texts_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

static bool determine_pbuffer_position(bs_pbuffer_t *pbuffer)
{
    sfVector2f new_pos;

    if (pbuffer == NULL)
        return (false);
    new_pos.x = pbuffer->pos.x + pbuffer->offset.x;
    new_pos.y = pbuffer->pos.y + pbuffer->offset.y;
    sfSprite_setPosition(pbuffer->sprite, new_pos);
    return (true);
}

/**
 * @brief Renders a pixel buffer
 * 
 * @param pbuffer 
 * @param color 
 * @return true 
 * @return false 
 */
bool bs_pbuffer_render(bs_frame_t *frame, bs_pbuffer_t *pbuffer)
{
    if (pbuffer == NULL || frame == NULL) {
        return (false);
    }
    sfTexture_updateFromPixels(pbuffer->texture, pbuffer->pixels, \
    pbuffer->width, pbuffer->height, 0, 0);
    sfSprite_setTexture(pbuffer->sprite, pbuffer->texture, sfFalse);
    determine_pbuffer_position(pbuffer);
    sfRenderWindow_drawSprite(frame->window, pbuffer->sprite, \
    pbuffer->rs);
    return (true);
}
