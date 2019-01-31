/*
** BillyScene, 2018
** bs_init_render_states
** File description:
** bs_init_render_states
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Init render system
 */
sfRenderStates *bs_init_render_states(void)
{
    sfRenderStates *states = malloc(sizeof(sfRenderStates));

    if (states == NULL)
        return (NULL);
    states->texture = NULL;
    states->shader = NULL;
    states->transform = sfTransform_Identity;
    states->blendMode = sfBlendAlpha;
    return (states);
}
