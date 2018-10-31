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
 * @brief Sets the base texture of the button
 * 
 * @param button 
 * @param path 
 * @return int 
 */
int bs_button_set_base_texture(bs_button_t *button, char *path)
{
	sfTexture *texture = NULL;

	if (button == NULL)
		return (0);
	texture = sfTexture_createFromFile(path, NULL);
	if (texture == NULL)
		return (0);
	if (button->texture_base)
		sfTexture_destroy(button->texture_base);
	button->texture_base = texture;
	return (1);
}
