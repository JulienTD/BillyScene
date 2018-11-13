/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Gets pbuffer in a scene by its id
 * 
 * @param scene 
 * @param id 
 * @return bs_label_t* 
 */
bs_pbuffer_t *bs_pbuffer_get_by_id(bs_scene_t *scene, char *id)
{
	bs_list_t *curr = NULL;
	bs_pbuffer_t *pbuffer = NULL;

	if (scene == NULL || id == NULL)
		return NULL;
	curr = scene->pbuffer_list;
	while (curr) {
		pbuffer = (bs_pbuffer_t *)curr->data;
		if (bs_str_are_equals(id, pbuffer->id_pbuffer)) {
			return (pbuffer);
		}
		curr = curr->next;
	}
	return (NULL);
}
