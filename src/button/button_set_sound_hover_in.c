/*
** BillyScene, 2018
** bs_button_set_sound_hover_in
** File description:
** Sets the sound hover in of the selected button
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the sound hover in of the selected button
 *
 * @param button 
 * @param path 
 * @return bool
 */
bool bs_button_set_sound_hover_in(bs_button_t *button, char *path)
{
    if (button == NULL)
        return (false);
    if (path == NULL) {
        if (button->sound_hover_in)
            bs_sound_destroy(button->sound_hover_in);
        button->sound_hover_in = NULL;
        return (true);
    }
    if (button->sound_hover_in == NULL) {
        button->sound_hover_in = bs_sound_create(path);
    } else {
        bs_sound_set_new(button->sound_hover_in, path);
    }
    if (button->sound_hover_in == NULL)
        return (false);
    return (true);
}
