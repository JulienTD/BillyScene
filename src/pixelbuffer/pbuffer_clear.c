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
 * @brief Clears a pbuffer with a color
 *
 * @param pbuffer 
 * @param color 
 * @return true 
 * @return false 
 */
bool bs_pbuffer_clear(bs_pbuffer_t *pbuffer, sfColor color)
{
	if (pbuffer == NULL) {
		return (false);
	}
	for (unsigned int y = 0; y < pbuffer->height; y++) {
		for (unsigned int x = 0; x < pbuffer->width; x++) {
			bs_pbuffer_set_pixel(pbuffer, x, y, color);
		}
	}
	return (true);
}
