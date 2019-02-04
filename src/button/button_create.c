/*
** BillyScene, 2018
** bs_button_create
** File description:
** Creates a button from an id, a width and an size
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Init button textures
 * 
 * @param button 
 * @return true 
 * @return false 
 */
static bool init_button_textures(bs_button_t *button)
{
    button->texture_base = NULL;
    button->texture_hover = NULL;
    button->texture_clicked = NULL;
    return (true);
}

/**
 * @brief Init button sounds
 * 
 * @param button 
 * @return true 
 * @return false 
 */
static bool init_button_sounds(bs_button_t *button)
{
    button->sound_click = NULL;
    button->sound_hover_in = NULL;
    button->sound_hover_out = NULL;
    return (true);
}

/**
 * @brief Init button events
 * 
 * @param button 
 * @return true 
 * @return false 
 */
static bool init_button_events(bs_button_t *button)
{
    button->click_pressed_event = NULL;
    button->click_released_event = NULL;
    button->hover_event = NULL;
    button->hover_in_event = NULL;
    button->hover_out_event = NULL;
    return (true);
}

/**
 * @brief Init button with default params
 * 
 * @param button 
 * @param id 
 * @return true 
 * @return false 
 */
static bool init_button_default_param(bs_button_t *button, char *id)
{
    button->id_button = NULL;
    button->id_button = bs_set_str_to(button->id_button, id);
    if (button->id_button == NULL)
        return (false);
    button->status = NORMAL;
    button->texture_status = 0;
    button->enabled = true;
    button->layer = 0;
    button->rs = bs_init_render_states();
    if (button->rs == NULL)
        return (false);
    return (true);
}

/**
 * @brief Creates a button from an id, a width and an size
 *
 * @param pos_x
 * @param pos_y
 * @param width
 * @param heigth
 * @return bs_button_t
 */
bs_button_t *bs_button_create(char *id, float width, float heigth)
{
    bs_button_t *button = NULL;

    if (id == NULL)
        return (NULL);
    button = malloc(sizeof(bs_button_t));
    if (button == NULL)
        return (NULL);
    button->rect = sfRectangleShape_create();
    if (button->rect == NULL)
        return (NULL);
    bs_button_set_size(button, width, heigth);
    bs_button_set_pos(button, 0, 0);
    bs_button_set_offset(button, 0, 0);
    init_button_events(button);
    init_button_sounds(button);
    init_button_textures(button);
    init_button_default_param(button, id);
    return (button);
}
