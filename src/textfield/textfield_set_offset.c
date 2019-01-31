/*
** BillyScene, 2018
** textfield_set_offset
** File description:
** bs_textfield_set_offset
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Change textfield offset
 * 
 * @param offset_x
 * @param offset_y
 */
bool bs_textfield_set_offset(bs_textfield_t *textfield, \
float offset_x, float offset_y)
{
    if (textfield == NULL) {
        return (false);
    }
    textfield->offset.x = offset_x;
    textfield->offset.y = offset_y;
    return (true);
}
