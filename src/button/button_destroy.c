/*
** BillyScene, 2018
** button_destroy
** File description:
** bs_button_destroy
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Destroy button's textures
 * 
 * @param button
 */
static void destroy_textures(bs_button_t *button)
{
    if (button->texture_base)
        sfTexture_destroy(button->texture_base);
    if (button->texture_hover)
        sfTexture_destroy(button->texture_hover);
    if (button->texture_clicked)
        sfTexture_destroy(button->texture_clicked);
}

/**
 * @brief Destroy button's sounds
 * 
 * @param button
 */
static void destroy_sounds(bs_button_t *button)
{
    if (button->sound_click)
        bs_sound_destroy(button->sound_click);
    if (button->sound_hover_in)
        bs_sound_destroy(button->sound_hover_in);
    if (button->sound_hover_out)
        bs_sound_destroy(button->sound_hover_out);
}

/**
 * @brief Destroy a button
 * 
 * @param button
 */
void bs_button_destroy(bs_button_t *button)
{
    if (button == NULL)
        return;
    if (button->id_button)
        free(button->id_button);
    if (button->rect)
        sfRectangleShape_destroy(button->rect);
    destroy_textures(button);
    destroy_sounds(button);
    if (button->rs)
        free(button->rs);
    free(button);
}
