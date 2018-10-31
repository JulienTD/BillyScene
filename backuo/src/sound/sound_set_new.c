/*
** EPITECH PROJECT, 2018
** sound_manager
** File description:
** sound_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

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
