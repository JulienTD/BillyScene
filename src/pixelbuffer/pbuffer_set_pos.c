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
 * @brief Sets the pbuffer's position
 * If pos_x is negative then the pos x won't change
 * If pos_y is negative then the pos y won't change
 * 
 * @param pbuffer 
 * @param pos_x 
 * @param pos_y 
 * @return true 
 * @return false 
 */
bool bs_pbuffer_set_pos(bs_pbuffer_t *pbuffer, int pos_x, int pos_y)
{
	if (pbuffer == NULL) {
		return (false);
	}
	if (pos_x >= 0) {
		pbuffer->pos_x = pos_x;
	}
	if (pos_y >= 0) {
		pbuffer->pos_y = pos_y;
	}
	return (true);
}
