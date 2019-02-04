/*
** BillyScene, 2018
** label_set_pos
** File description:
** bs_label_set_color
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Sets label's color
 * 
 * @param label
 * @param color
 * @return true
 * @return false
 */
bool bs_label_set_color(bs_label_t *label, sfColor color)
{
    if (label == NULL) {
        return (false);
    }
    sfText_setColor(label->text, color);
    return (true);
}
