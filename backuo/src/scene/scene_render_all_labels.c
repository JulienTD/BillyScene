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
 * @brief Renders all scene's labels
 * 
 * @param scene 
 * @param frame 
 * @return true 
 * @return false 
 */
bool bs_scene_render_all_labels(bs_scene_t *scene, bs_frame_t *frame)
{
	bs_list_t *list = NULL;
	bs_label_t *label = NULL;

	if (scene == NULL || frame == NULL)
		return (false);
	list = scene->label_list;
	while (list) {
		label = (bs_label_t *)list->data;
		//bs_render_text(frame, label);
		list = list->next;
	}
	return (true);
}
