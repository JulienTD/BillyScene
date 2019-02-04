/*
** BillyScene, 2019
** textfield_set_layer
** File description:
** Sets the textfield's layer
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the textfield's layer
 *
 * @param button
 * @return true
 * @return false
 */
bool bs_textfield_set_layer(bs_textfield_t *textfield, short layer)
{
    if (textfield == NULL)
        return (false);
    textfield->layer = layer;
    return (true);
}
