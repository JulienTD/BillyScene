/*
** BillyScene, 2018
** pbuffer_set_pos
** File description:
** bs_pbuffer_set_pos
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Sets the pbuffer's position
 * @param pbuffer
 * @param pos_x
 * @param pos_y
 * @return true
 * @return false
 */
bool bs_pbuffer_set_pos(bs_pbuffer_t *pbuffer, float pos_x, float pos_y)
{
    if (pbuffer == NULL) {
        return (false);
    }
    pbuffer->pos.x = pos_x;
    pbuffer->pos.y = pos_y;
    return (true);
}
