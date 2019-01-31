/*
** BillyScene, 2018
** pbuffer_destroy
** File description:
** bs_pbuffer_destroy
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Destroys a pbuffer
 * 
 * @param pbuffer 
 */
void bs_pbuffer_destroy(bs_pbuffer_t *pbuffer)
{
    if (pbuffer == NULL)
        return;
    if (pbuffer->pixels)
        free(pbuffer->pixels);
    if (pbuffer->sprite)
        sfSprite_destroy(pbuffer->sprite);
    if (pbuffer->texture)
        sfTexture_destroy(pbuffer->texture);
    if (pbuffer->id_pbuffer)
        free(pbuffer->id_pbuffer);
    if (pbuffer->rs)
        free(pbuffer->rs);
    free(pbuffer);
}
