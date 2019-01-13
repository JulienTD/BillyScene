/*
** EPITECH PROJECT, 2018
** button_create
** File description:
** function to create a button structure
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the size of the button.
 * If width < 0 then its width won't change
 * If height < 0 then its height won't change
 * 
 * @param button 
 * @param pos_x 
 * @param pos_y 
 * @return true 
 * @return false 
 */
bool bs_button_set_size(bs_button_t *button, float width, float height)
{
    sfVector2f size = {.x = width, .y = height};
    sfVector2f curr_size;

    if (button == NULL) {
        return (false);
    }
    curr_size = sfRectangleShape_getSize(button->rect);
    size.x = (width < 0) ? curr_size.x : width;
    size.y = (height < 0) ? curr_size.y : height;
    sfRectangleShape_setSize(button->rect, size);
    return (true);
}