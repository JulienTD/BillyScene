/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Gets label in a scene by its id
 * 
 * @param scene 
 * @param id 
 * @return bs_label_t* 
 */
bs_label_t *bs_label_get_by_id(bs_scene_t *scene, char *id)
{
	bs_list_t *curr = NULL;
	bs_label_t *label = NULL;

	if (scene == NULL || id == NULL)
		return NULL;
	curr = scene->label_list;
	while (curr) {
		label = (bs_label_t *)curr->data;
		if (bs_str_are_equals(id, label->id_label)) {
			return (label);
		}
		curr = curr->next;
	}
	return (NULL);
}
