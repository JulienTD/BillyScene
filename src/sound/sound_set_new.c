/*
** BillyScene, 2018
** sound_set_new
** File description:
** bs_sound_set_new
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Set new sound to struct.
 * 
 * @param sound
 * @param path
 */
bool bs_sound_set_new(bs_sound_t *sound, char *path)
{
    if (sound == NULL) {
        return false;
    }
    if (sound->buffer) {
        sfSoundBuffer_destroy(sound->buffer);
    }
    if (sound->sound == NULL) {
        sound->sound = sfSound_create();
        if (sound->sound == NULL) {
            return false;
        }
    }
    sound->buffer = sfSoundBuffer_createFromFile(path);
    if (sound->buffer == NULL) {
        return NULL;
    }
    sfSound_setBuffer(sound->sound, sound->buffer);
    return true;
}
