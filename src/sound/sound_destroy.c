/*
** BillyScene, 2018
** sound_destroy
** File description:
** bs_sound_destroy
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Destroy Sound struct
 * 
 * @param sound
 */
void bs_sound_destroy(bs_sound_t *sound)
{
    if (sound == NULL)
        return;
    if (sound->buffer)
        sfSoundBuffer_destroy(sound->buffer);
    if (sound->sound)
        sfSound_destroy(sound->sound);
    if (sound->id_sound)
        free(sound->id_sound);
    free(sound);
}
