/*
** BillyScene, 2018
** textfield_set_pos
** File description:
** bs_textfield_set_pos
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Set textfield pos
 * 
 * @param textfield
 * @param pos_x
 * @param pos_y
 */
bool bs_textfield_set_pos(bs_textfield_t *textfield, float pos_x, float pos_y)
{
    if (textfield == NULL) {
        return (false);
    }
    textfield->pos.x = pos_x;
    textfield->pos.y = pos_y;
    return (true);
}
