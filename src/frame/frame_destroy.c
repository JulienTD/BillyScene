/*
** EPITECH PROJECT, 2018
** create_frame
** File description:
** create_frame
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

// static bool destroy_all_scenes(bs_list_t **head)
// {
// 	bs_list_t *curr = NULL;
// 	bs_scene_t *scene = NULL;

// 	if (head == NULL)
// 		return (true);
// 	curr = *head;
// 	while (curr) {
// 		scene = (bs_scene_t *)curr->data;		
// 		bs_scene_destroy(scene);
// 		curr = curr->next;
// 	}
// 	return (true);
// }

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
	bs_list_destroy(&(frame->scenes), \
	(_Bool (*)(void *))&bs_scene_destroy);
	free(frame);
	return true;
}