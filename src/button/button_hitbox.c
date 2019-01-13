#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

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
    return (clickX <= sfRectangleShape_getPosition(button.rect).x
        + sfRectangleShape_getSize(button.rect).x &&
        clickX >= sfRectangleShape_getPosition(button.rect).x
        &&
        clickY <= sfRectangleShape_getPosition(button.rect).y
        + sfRectangleShape_getSize(button.rect).y &&
        clickY >= sfRectangleShape_getPosition(button.rect).y);
}
