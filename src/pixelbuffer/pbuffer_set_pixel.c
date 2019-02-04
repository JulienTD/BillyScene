/*
** BillyScene, 2018
** pbuffer_set_pixel
** File description:
** bs_pbuffer_set_pixel
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Sets pixel in pixelbuffer
 * 
 * @param pbuffer
 * @param x
 * @param y
 * @param color
 * @return true
 * @return false
 */
bool bs_pbuffer_set_pixel(bs_pbuffer_t *pbuffer, \
unsigned int x, unsigned int y, sfColor color)
{
    unsigned int pixel_index = 0;

    if (pbuffer == NULL) {
        return (false);
    }
    pixel_index = 4 * (x + y * pbuffer->width);
    if (x > pbuffer->width || y > pbuffer->height) {
        return (false);
    }
    pbuffer->pixels[pixel_index] = color.r;
    pbuffer->pixels[pixel_index + 1] = color.g;
    pbuffer->pixels[pixel_index + 2] = color.b;
    pbuffer->pixels[pixel_index + 3] = color.a;
    return (true);
}
