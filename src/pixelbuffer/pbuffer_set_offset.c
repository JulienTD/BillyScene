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
 * @brief Sets the pbuffer's offset
 * 
 * @param pbuffer 
 * @param offset_x 
 * @param offset_y 
 * @return true 
 * @return false 
 */
bool bs_pbuffer_set_offset(bs_pbuffer_t *pbuffer, \
float offset_x, float offset_y)
{
	if (pbuffer == NULL) {
		return (false);
	}
	pbuffer->offset.x = offset_x;
	pbuffer->offset.y = offset_y;
	return (true);
}
