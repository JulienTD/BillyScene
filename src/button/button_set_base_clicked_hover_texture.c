/*
** BillyScene, 2018
** button_set_base_clicked_hover_texture
** File description:
** bs_button_set_base_clicked_hover_texture
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Sets the base/clicked/hover texture of the button
 * 
 * @param button
 * @param path
 * @return bool
 */
bool bs_button_set_base_clicked_hover_texture(bs_button_t *button, char *path)
{
    bs_button_set_texture_base(button, path);
    bs_button_set_texture_hover(button, path);
    bs_button_set_texture_clicked(button, path);
    return (true);
}