/*
** EPITECH PROJECT, 2018
** label_set_pos
** File description:
** Sets the position of the label
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Sets the label's position
 * 
 * @param label 
 * @param pos_x 
 * @param pos_y 
 * @return true 
 * @return false 
 */
bool bs_label_set_pos(bs_label_t *label, float pos_x, float pos_y)
{
    sfVector2f pos = {.x = pos_x, .y = pos_y};
    sfVector2f curr_pos;

    if (label == NULL) {
        return false;
    }
    curr_pos = label->pos;
    pos.x = (pos_x < 0) ? curr_pos.x : pos_x;
    pos.y = (pos_y < 0) ? curr_pos.y : pos_y;
    label->pos = pos;
    return (true);
}