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
 * @brief Free the frame structure
 * 
 * @param frame 
 * @return true 
 * @return false 
 */
bool bs_frame_destroy(bs_frame_t *frame)
{
	if (frame == NULL)
		return true;
	if (frame->window)
		sfRenderWindow_destroy(frame->window);
	if (frame->clock)
		sfClock_destroy(frame->clock);
	if (frame->current_scene)
		free(frame->current_scene);
	if (frame->last_scene)
		free(frame->last_scene);
	if (frame->data)
		free(frame->data);
	free(frame);
	return true;
}