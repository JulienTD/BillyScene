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
 * @brief Renders all scene's sprites
 * 
 * @param scene 
 * @param frame 
 * @return true 
 * @return false 
 */
bool bs_scene_render_all_sprites(bs_scene_t *scene, bs_frame_t *frame)
{
	bs_list_t *list = NULL;
	bs_sprite_t *sprite = NULL;

	if (scene == NULL || frame == NULL)
		return (false);
	list = scene->sprite_list;
	while (list) {
		sprite = (bs_sprite_t *)list->data;
		bs_sprite_render(frame, sprite);
		list = list->next;
	}
	return (true);
}