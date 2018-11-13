/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Adds pbuffer to the scene
 * 
 * @param scene 
 * @param pbuffer
 * @return true 
 * @return false 
 */
bool bs_pbuffer_add_to_scene(bs_scene_t *scene, bs_pbuffer_t *pbuffer)
{
	if (scene == NULL || pbuffer == NULL)
		return (false);
	return bs_list_push(&(scene->pbuffer_list), pbuffer) != NULL;
}
