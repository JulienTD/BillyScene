/*
** BillyScene, 2019
** pbuffer_set_layer
** File description:
** Sets the pixel buffer's layer
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the pixel buffer's layer
 *
 * @param button
 * @return true
 * @return false
 */
bool bs_pbuffer_set_layer(bs_pbuffer_t *pbuffer, short layer)
{
    if (pbuffer == NULL)
        return (false);
    pbuffer->layer = layer;
    return (true);
}
