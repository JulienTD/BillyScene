/*
** BillyScene, 2019
** button_hitbox
** File description:
** bs_is_mouse_on_button
*/

#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Checks if x and y is on the button
 * 
 * @param button
 * @param clickX
 * @param clickY
 * @return int
 */
bool bs_is_mouse_on_button(bs_button_t button, float clickX, float clickY)
{
    return (clickX <= button.pos.x
        + sfRectangleShape_getSize(button.rect).x + button.offset.x \
        && clickX >= button.pos.x + button.offset.x
        &&
        clickY <= button.pos.y
        + sfRectangleShape_getSize(button.rect).y + button.offset.y &&
        clickY >= button.pos.y + button.offset.y);
}
