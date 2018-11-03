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
 * @return bs_scene_t* 
 */
bool bs_scene_destroy(bs_scene_t *scene)
{
	if (scene == NULL)
		return (true);
	if (scene->id_scene)
		free(scene->id_scene);
	bs_list_destroy(&(scene->button_list), \
			(_Bool (*)(void *))&bs_button_destroy);
	bs_list_destroy(&(scene->label_list), \
			(_Bool (*)(void *))&bs_label_destroy);
	bs_list_destroy(&(scene->sprite_list), \
			(_Bool (*)(void *))&bs_sprite_destroy);
	bs_list_destroy(&(scene->textfield_list), \
			(_Bool (*)(void *))&bs_textfield_destroy);
	free(scene);
	return (true);
}