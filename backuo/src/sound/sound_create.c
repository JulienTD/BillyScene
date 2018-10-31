/*
** EPITECH PROJECT, 2018
** sound_manager
** File description:
** sound_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

bs_sound_t *bs_sound_create(char *path)
{
	bs_sound_t *sound = malloc(sizeof(bs_sound_t));

	if (sound == NULL)
		return (NULL);
	sound->buffer = NULL;
	sound->id_sound = NULL;
	sound->sound = NULL;
	if (path == NULL) {
		return sound;
	}
	sound->sound = sfSound_create();
	sound->buffer = sfSoundBuffer_createFromFile(path);
	if (sound->sound == NULL || sound->buffer == NULL)
		return (NULL);
	sfSound_setBuffer(sound->sound, sound->buffer);
	return sound;
}
