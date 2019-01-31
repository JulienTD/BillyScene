/*
** BillyScene, 2018
** label_set_pos
** File description:
** bs_label_set_str
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Sets str to the label
 * 
 * @param label
 * @param str
 * @return true
 * @return false
 */
bool bs_label_set_str(bs_label_t *label, char *str)
{
    if (label == NULL) {
        return (false);
    }
    if (str == NULL) {
        sfText_setString(label->text, "");
        return (true);
    }
    sfText_setString(label->text, str);
    return (true);
}
