#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Checks if x and y is on the textfield
 *
 * @param textfield
 * @param clickX
 * @param clickY
 * @return int
 */
bool bs_is_mouse_on_textfield(bs_textfield_t textfield, \
float clickX, float clickY)
{
    return (clickX < sfRectangleShape_getPosition(textfield.rect).x
        + sfRectangleShape_getSize(textfield.rect).x &&
        clickX > sfRectangleShape_getPosition(textfield.rect).x
        &&
        clickY < sfRectangleShape_getPosition(textfield.rect).y
        + sfRectangleShape_getSize(textfield.rect).y &&
        clickY > sfRectangleShape_getPosition(textfield.rect).y);
}
