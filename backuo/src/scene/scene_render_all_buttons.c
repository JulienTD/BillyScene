/*
** EPITECH PROJECT, 2018
** scene_helper
** File description:
** scene_helper
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Renders all scene's buttons
 * 
 * @param scene 
 * @param frame 
 * @return true 
 * @return false 
 */
bool bs_scene_render_all_buttons(bs_scene_t *scene, bs_frame_t *frame)
{
	bs_list_t *list = NULL;
	bs_button_t *button = NULL;

	if (scene == NULL || frame == NULL)
		return (false);
	list = scene->button_list;
	while (list) {
		button = (bs_button_t *)list->data;
		bs_button_render(frame, button);
		list = list->next;
	}
	return (true);
}
