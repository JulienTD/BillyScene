/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Destroys sprite
 * 
 * @param sprite 
 * @return true 
 * @return false 
 */
bool bs_sprite_destroy(bs_sprite_t *sprite)
{
	if (sprite == NULL)
		return (true);
	bs_list_destroy(&sprite->anims, \
		(_Bool (*)(void *))&bs_sprite_anim_destroy);
	if (sprite->curr_anim)
		free(sprite->curr_anim);
	if (sprite->id_sprite)
		free(sprite->id_sprite);
	if (sprite->sprite)
		sfSprite_destroy(sprite->sprite);
	if (sprite->texture)
		sfTexture_destroy(sprite->texture);
	free(sprite);
	return (true);
}