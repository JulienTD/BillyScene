/*
** BillyScene, 2018
** label_render
** File description:
** bs_label_render
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

static bool determine_label_position(bs_label_t *label)
{
    sfVector2f new_pos = {.x = 0, .y = 0};

    if (label == NULL)
        return (false);
    new_pos.x = label->pos.x + label->offset.x;
    new_pos.y = label->pos.y + label->offset.y;
    sfText_setPosition(label->text, new_pos);
    return (true);
}

/**
 * @brief Render label
 * 
 * @param frame
 * @param label
 */
bool bs_label_render(bs_frame_t *frame, bs_label_t *label)
{
    if (frame == NULL || label == NULL || label->enabled == false)
        return (false);
    sfText_setFont(label->text, label->font);
    determine_label_position(label);
    sfRenderWindow_drawText(frame->window, label->text, label->rs);
    return (true);
}
