/*
** BillyScene, 2018
** textfield_render
** File description:
** bs_textfield_render
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Render textfield 
 * 
 * @param frame
 * @param textfield
 */
bool bs_textfield_render(bs_frame_t *frame, bs_textfield_t *textfield)
{
    if (frame == NULL || textfield == NULL || textfield->enabled == false)
        return (false);
    if (textfield->texture)
        sfRectangleShape_setTexture(textfield->rect, \
        textfield->texture, sfFalse);
    sfRectangleShape_setPosition(textfield->rect, textfield->pos);
    bs_label_set_pos(textfield->label, textfield->pos.x, \
    textfield->pos.y);
    sfRenderWindow_drawRectangleShape(frame->window, textfield->rect, \
    textfield->rs);
    bs_label_render(frame, textfield->label);
    return (true);
}