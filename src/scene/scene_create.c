/*
** EPITECH PROJECT, 2017
** scene_manager
** File description:
** scene_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Creates scene
 * 
 * @param id 
 * @return bs_scene_t* 
 */
bs_scene_t *bs_scene_create(char *id)
{
	bs_scene_t *scene = malloc(sizeof(bs_scene_t));

	if (scene == NULL)
		return (NULL);
	scene->id_scene = id;
	scene->button_list = NULL;
	scene->sprite_list = NULL;
	scene->label_list = NULL;
	scene->textfield_list = NULL;
	scene->event_key_pressed = NULL;
	scene->event_mouse_pressed = NULL;
	scene->event_mouse_released = NULL;
	scene->event_mouse_moved = NULL;
	scene->event_mouse_wheel_scrolled = NULL;
	scene->event_tick = NULL;
	scene->event_init = NULL;
	scene->event_init_post = NULL;
	scene->current_tick = 0;
	return (scene);
}