/*
** BillyScene, 2018
** button_set_texture_clicked
** File description:
** bs_button_set_texture_clicked
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Sets the clicked texture of the button
 * 
 * @param button
 * @param path
 * @return bool
 */
bool bs_button_set_texture_clicked(bs_button_t *button, char *path)
{
    sfTexture *texture = NULL;

    if (button == NULL)
        return (false);
    texture = sfTexture_createFromFile(path, NULL);
    if (texture == NULL)
        return (false);
    if (button->texture_clicked)
        sfTexture_destroy(button->texture_clicked);
    button->texture_clicked = texture;
    return (true);
}
