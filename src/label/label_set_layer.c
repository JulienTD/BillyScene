/*
** BillyScene, 2019
** label_set_layer
** File description:
** Sets the label's layer
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the label's layer
 *
 * @param button
 * @return true
 * @return false
 */
bool bs_label_set_layer(bs_label_t *label, short layer)
{
    if (label == NULL)
        return (false);
    label->layer = layer;
    return (true);
}
