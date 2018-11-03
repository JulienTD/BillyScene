/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

bool bs_sprite_anim_destroy(bs_sprite_anim_t *anim)
{
	if (anim == NULL)
		return (true);
	if (anim->id_anim)
		free(anim->id_anim);
	if (anim->sprite)
		sfSprite_destroy(anim->sprite);
	if (anim->texture)
		sfTexture_destroy(anim->texture);
	free(anim);
	return (true);
}