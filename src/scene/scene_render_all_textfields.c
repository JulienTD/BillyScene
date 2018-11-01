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
 * @brief Renders all scene's textfields
 * 
 * @param scene 
 * @param frame 
 * @return true 
 * @return false 
 */
bool bs_scene_render_all_textfields(bs_scene_t *scene, bs_frame_t *frame)
{
	bs_list_t *list = NULL;
	bs_textfield_t *textfield = NULL;

	if (scene == NULL || frame == NULL)
		return (false);
	list = scene->textfield_list;
	while (list) {
		textfield = (bs_textfield_t *)list->data;
		bs_textfield_render(frame, textfield);
		list = list->next;
	}
	return (true);
}