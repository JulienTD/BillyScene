/*
** EPITECH PROJECT, 2018
** button_music_helper
** File description:
** Helps to manipulate button's sound
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the sound hover out of the selected button
 *
 * @param button 
 * @param path 
 * @return int 
 */
bool bs_button_set_sound_hover_out(bs_button_t *button, char *path)
{
	if (button == NULL)
		return (false);
	if (path == NULL) {
		if (button->sound_hover_out)
			bs_sound_destroy(button->sound_hover_out);
		button->sound_hover_out = NULL;
		return (true);
	}
	if (button->sound_hover_out == NULL) {
		button->sound_hover_out = bs_sound_create(path);
	} else {
		bs_sound_set_new(button->sound_hover_out, path);
	}
	return (true);
}