/*
** EPITECH PROJECT, 2018
** create_frame
** File description:
** create_frame
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Sets the new frame cursor
 * 
 * @return bool 
 */
bool bs_frame_set_cursor(bs_frame_t *frame, char *path)
{
	if (frame == NULL || frame->window == NULL) {
		return (false);
	}
	if (path == NULL) {
		if (frame->cursor != NULL) {
			bs_sprite_destroy(frame->cursor);
			frame->cursor = NULL;
			sfRenderWindow_setMouseCursorVisible(frame->window, \
			true);
			return (true);
		}
	}
	frame->cursor = bs_sprite_create("cursor", path);
	sfRenderWindow_setMouseCursorVisible(frame->window, false);
	return (true);
}
