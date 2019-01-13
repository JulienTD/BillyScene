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
 * @brief Sets the offset of the button
 * 
 * @param button 
 * @param pos_x 
 * @param pos_y 
 * @return true 
 * @return false 
 */
bool bs_button_set_offset(bs_button_t *button, float offset_x, float offset_y)
{
    if (button == NULL) {
        return (false);
    }
    button->offset.x = offset_x;
    button->offset.y = offset_y;
    return (true);
}
