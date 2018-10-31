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
 * @brief Sets the sound click of the selected button
 *
 * @param button 
 * @param path 
 * @return bool 
 */
bool bs_button_set_sound_click(bs_button_t *button, char *path)
{
	if (button == NULL)
		return (false);
	if (path == NULL) {
		if (button->sound_click)
			bs_sound_free(button->sound_click);
		button->sound_click = NULL;
		return (true);
	}
	if (button->sound_click == NULL) {
		button->sound_click = bs_sound_create(path);
	} else {
		bs_sound_set_new(button->sound_click, path);
	}
	return (true);
}
