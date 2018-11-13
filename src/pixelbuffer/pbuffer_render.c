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
 * @brief Renders a pixel buffer
 * 
 * @param pbuffer 
 * @param color 
 * @return true 
 * @return false 
 */
bool bs_pbuffer_render(bs_frame_t *frame, bs_pbuffer_t *pbuffer)
{
	sfRenderStates *rstates = NULL;

	if (pbuffer == NULL) {
		return (false);
	}
	rstates = bs_init_render_states();
	sfTexture_updateFromPixels(pbuffer->texture, pbuffer->pixels, \
	pbuffer->width, pbuffer->height, 0, 0);
	sfSprite_setTexture(pbuffer->sprite, pbuffer->texture, sfFalse);
	sfRenderWindow_drawSprite(frame->window, pbuffer->sprite, rstates);
	free(render_states);
	return (true);
}
