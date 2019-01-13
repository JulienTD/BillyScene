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
 * @brief Destroys textfield
 * 
 * @param textfield 
 */
void bs_textfield_destroy(bs_textfield_t *textfield)
{
    if (textfield == NULL)
        return;
    if (textfield->id_textfield)
        free(textfield->id_textfield);
    bs_label_destroy(textfield->label);
    if (textfield->rect)
        sfRectangleShape_destroy(textfield->rect);
    if (textfield->texture)
        sfTexture_destroy(textfield->texture);
    if (textfield->rs)
        free(textfield->rs);
}
