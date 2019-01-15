/*
** EPITECH PROJECT, 2019
** BillyScene
** File description:
** bs_sound
*/

#ifndef BS_SOUND_H_
    #define BS_SOUND_H_

#include <SFML/Audio.h>

typedef struct bs_sound_s
{
    char *id_sound;
    sfSound *sound;
    sfSoundBuffer *buffer;
} bs_sound_t;

/*    PROTOTYPES    */
bs_sound_t *bs_sound_create(char *path);
bool bs_sound_play(bs_sound_t *sound);
bool bs_sound_set_new(bs_sound_t *sound, char *path);
void bs_sound_destroy(bs_sound_t *sound);

#endif /* !BS_SOUND_H_ */
