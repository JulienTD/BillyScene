/*
** EPITECH PROJECT, 2018
** button_texture_helper
** File description:
** Helps to manipulate button's texture
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the base/clicked/hover texture of the button
 * 
 * @param button 
 * @param path 
 * @return int 
 */
int bs_button_set_base_clicked_hover_texture(bs_button_t *button, char *path)
{
	bs_button_set_base_texture(button, path);
	bs_button_set_hover_texture(button, path);
	bs_button_set_clicked_texture(button, path);
	return (1);
}