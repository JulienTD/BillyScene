/*
** BillyScene, 2018
** label_set_pos
** File description:
** bs_label_set_offset
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Sets the label's offset
 * 
 * @param label
 * @param pos_x
 * @param pos_y
 * @return true
 * @return false
 */
bool bs_label_set_offset(bs_label_t *label, float offset_x, float offset_y)
{
    if (label == NULL) {
        return false;
    }
    label->offset.x = offset_x;
    label->offset.y = offset_y;
    return (true);
}