/*
** EPITECH PROJECT, 2019
** BillyScene
** File description:
** bs_frame
*/

#ifndef BS_FRAME_H_
    #define BS_FRAME_H_

#include <SFML/Graphics.h>
#include "components/bs_list.h"

typedef struct bs_frame_s
{
    int height;
    int width;
    sfEvent event;
    sfRenderWindow *window;
    sfClock *clock;
    char *current_scene;
    char *last_scene;
    bs_list_t *scenes;
    int components_volume_level;
    int max_tick;
    struct bs_sprite_s *cursor;
    void *data;
} bs_frame_t;

/*    PROTOTYPES    */
bs_frame_t *bs_frame_create(void);
void bs_frame_destroy(bs_frame_t *frame);
bool bs_frame_set_cursor(bs_frame_t *frame, char *path);

#endif /* !BS_FRAME_H_ */
