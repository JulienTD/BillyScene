/*
** BillyScene, 2018
** pbuffer_create
** File description:
** bs_pbuffer_create
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Creates a pbuffer
 * 
 * @param width
 * @param height
 * @return bs_pbuffer_t*
 */
bs_pbuffer_t *bs_pbuffer_create(char *id, unsigned int width, \
unsigned int height)
{
    bs_pbuffer_t *pbuffer = malloc(sizeof(bs_pbuffer_t));

    if (pbuffer == NULL)
        return (NULL);
    pbuffer->height = height;
    pbuffer->width = width;
    pbuffer->pixels = malloc((width * height * 4) * sizeof(sfUint8));
    if (pbuffer == NULL) {
        free(pbuffer);
        return (NULL);
    }
    bs_pbuffer_set_pos(pbuffer, 0, 0);
    bs_pbuffer_set_offset(pbuffer, 0, 0);
    pbuffer->texture = sfTexture_create(width, height);
    pbuffer->sprite = sfSprite_create();
    pbuffer->id_pbuffer = NULL;
    pbuffer->id_pbuffer = bs_set_str_to(pbuffer->id_pbuffer, id);
    pbuffer->rs = bs_init_render_states();
    bs_pbuffer_clear(pbuffer, sfBlack);
    return (pbuffer);
}
