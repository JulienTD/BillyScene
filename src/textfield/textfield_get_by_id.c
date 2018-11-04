/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Gets textfield in a scene by its id
 * 
 * @param scene 
 * @param id 
 * @return bs_textfield_t* 
 */
bs_textfield_t *bs_textfield_get_by_id(bs_scene_t *scene, char *id)
{
	bs_list_t *curr = NULL;
	bs_textfield_t *textfield = NULL;

	if (scene == NULL || id == NULL)
		return NULL;
	curr = scene->textfield_list;
	while (curr) {
		textfield = (bs_textfield_t *)curr->data;
		if (bs_str_are_equals(id, textfield->id_textfield)) {
			return (textfield);
		}
		curr = curr->next;
	}
	return (NULL);
}
