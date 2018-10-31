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
 * @brief Create frame structure
 * 
 * @return bs_frame_t* 
 */
bs_frame_t *bs_frame_create(void)
{
	bs_frame_t *frame = malloc(sizeof(bs_frame_t));

	if (frame == NULL)
		return (NULL);
	frame->height = 0;
	frame->width = 0;
	frame->window = NULL;
	frame->clock = NULL;
	frame->current_scene = NULL;
	frame->last_scene = NULL;
	frame->scenes = NULL;	
	frame->components_volume_level = 50;
	frame->max_tick = 20;
	frame->data = NULL;
	return frame;
}