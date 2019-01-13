/*
** EPITECH PROJECT, 2017
** scene_manager
** File description:
** scene_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Destroys scene
 * 
 * @param id  
 */
void bs_scene_destroy(bs_scene_t *scene)
{
	if (scene == NULL)
		return;
	if (scene->id_scene)
		free(scene->id_scene);
	bs_list_destroy(&(scene->button_list), \
			(void (*)(void *))&bs_button_destroy);
	bs_list_destroy(&(scene->label_list), \
			(void (*)(void *))&bs_label_destroy);
	bs_list_destroy(&(scene->sprite_list), \
			(void (*)(void *))&bs_sprite_destroy);
	bs_list_destroy(&(scene->textfield_list), \
			(void (*)(void *))&bs_textfield_destroy);
	bs_list_destroy(&(scene->pbuffer_list), \
		(void (*)(void *))&bs_pbuffer_destroy);
	free(scene);
}
