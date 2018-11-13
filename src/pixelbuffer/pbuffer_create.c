/*
** EPITECH PROJECT, 2018
** texts_manager
** File description:
** texts_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Creates a pbuffer
 * 
 * @param width 
 * @param height 
 * @return bs_pbuffer_t* 
 */
bs_pbuffer_t *bs_pbuffer_create(unsigned int width, \
unsigned int height)
{
	bs_pbuffer_t *pbuffer = malloc(sizeof(bs_pbuffer_t));

	if (pbuffer == NULL) {
		return (NULL);
	}
	pbuffer->height = height;
	pbuffer->width = width;
	pbuffer->pixels = malloc((width * height * 4) * sizeof(sfUint8));
	if (pbuffer == NULL) {
		free(pbuffer);
		return (NULL);
	}
	pbuffer->pos_x = 0;
	pbuffer->pos_y = 0;
	pbuffer->texture = sfTexture_create(width, height);
	pbuffer->sprite = sfSprite_create();
	bs_pbuffer_clear(pbuffer, sfRed);
	return (pbuffer);
}