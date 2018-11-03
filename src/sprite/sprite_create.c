/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Creates a new sprite
 * 
 * @param id 
 * @param texture_path 
 * @return bs_sprite_t* 
 */
bs_sprite_t *bs_sprite_create(char *id, const char *texture_path)
{
	bs_sprite_t *element = malloc(sizeof(bs_sprite_t));
	sfVector2f scale = {1, 1};
	sfVector2f speed = {0, 0};
	sfVector2i size = {0, 0};

	if (element == NULL || texture_path == NULL)
		return (NULL);
	element->texture = sfTexture_createFromFile(texture_path, NULL);
	element->sprite = sfSprite_create();
	element->size = size;
	element->speed = speed;
	element->scale = scale;
	element->is_init = false;
	element->id_sprite = NULL;
	element->id_sprite = bs_set_str_to(element->id_sprite, id);
	element->curr_anim = NULL;
	element->enabled = true;
	element->curr_tick = 0;
	element->tick_max = 0;
	element->anims = NULL;
	return (element);
}