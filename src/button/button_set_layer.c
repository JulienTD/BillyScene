/*
** BillyScene, 2019
** button_set_layer
** File description:
** Sets the button's layer
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the button's layer
 *
 * @param button
 * @return true
 * @return false
 */
bool bs_button_set_layer(bs_button_t *button, short layer)
{
    if (button == NULL)
        return (false);
    button->layer = layer;
    return (true);
}
