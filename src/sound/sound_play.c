/*
** BillyScene, 2018
** sound_play
** File description:
** bs_sound_play
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Play sound
 * 
 * @param sound
 */
bool bs_sound_play(bs_sound_t *sound)
{
    if (sound == NULL) {
        return false;
    }
    if (sound->buffer == NULL || sound->sound == NULL) {
        return false;
    }
    sfSound_play(sound->sound);
    return true;
}
