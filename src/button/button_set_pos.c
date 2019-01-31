/*
** BillyScene, 2018
** bs_button_set_pos
** File description:
** Sets the position of the button
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the position of the button
 * 
 * @param button 
 * @param pos_x 
 * @param pos_y 
 * @return true 
 * @return false 
 */
bool bs_button_set_pos(bs_button_t *button, float pos_x, float pos_y)
{
    sfVector2f pos = {.x = pos_x, .y = pos_y};
    sfVector2f curr_pos;

    if (button == NULL)
        return (false);
    curr_pos = button->pos;
    pos.x = (pos_x < 0) ? curr_pos.x : pos_x;
    pos.y = (pos_y < 0) ? curr_pos.y : pos_y;
    button->pos = pos;
    return (true);
}
