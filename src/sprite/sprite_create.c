/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <SFML/Network.h>

static void init_params(bs_sprite_t *sprite)
{
	sprite->curr_anim = NULL;
	sprite->enabled = true;
	sprite->curr_tick = 0;
	sprite->tick_max = 0;
	sprite->anims = NULL;
}

/**
 * @brief Creates a new sprite
 * 
 * @param id 
 * @param texture_path 
 * @return bs_sprite_t* 
 */
bs_sprite_t *bs_sprite_create(char *id, const char *texture_path)
{
	bs_sprite_t *sprite = malloc(sizeof(bs_sprite_t));
	sfVector2f scale = {1, 1};
	sfVector2f speed = {0, 0};
	sfVector2i size = {0, 0};

	if (sprite == NULL || texture_path == NULL)
		return (NULL);
	sprite->texture = sfTexture_createFromFile(texture_path, NULL);
	sprite->sprite = sfSprite_create();
	sprite->size = size;
	sprite->speed = speed;
	sprite->scale = scale;
	sprite->is_init = false;
	sprite->id_sprite = NULL;
	init_params(sprite);
	sprite->id_sprite = bs_set_str_to(sprite->id_sprite, id);
	sprite->rs = bs_init_render_states();
	return (sprite);
}
