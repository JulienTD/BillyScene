/*
** BillyScene, 2018
** button_set_texture_hover
** File description:
** bs_button_set_texture_hover
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Sets the hover texture of the button
 * 
 * @param button
 * @param path
 * @return bool
 */
bool bs_button_set_texture_hover(bs_button_t *button, char *path)
{
    sfTexture *texture = NULL;

    if (button == NULL)
        return (false);
    texture = sfTexture_createFromFile(path, NULL);
    if (texture == NULL)
        return (false);
    if (button->texture_hover)
        sfTexture_destroy(button->texture_hover);
    button->texture_hover = texture;
    return (true);
}