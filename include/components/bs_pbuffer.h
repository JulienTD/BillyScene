/*
** EPITECH PROJECT, 2019
** BillyScene
** File description:
** bs_pbuffer
*/

#ifndef BS_PBUFFER_H_
    #define BS_PBUFFER_H_

#include <SFML/Graphics.h>
#include "components/bs_frame.h"
#include "components/bs_scene.h"

typedef struct bs_pbuffer_s
{
    char *id_pbuffer;
    sfVector2f pos;
    sfVector2f offset;
    short layer;
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
    sfSprite *sprite;
    sfTexture *texture;
    sfRenderStates *rs;
} bs_pbuffer_t;

/*    PROTOTYPES    */
bs_pbuffer_t *bs_pbuffer_create(char *id, unsigned int width, \
unsigned int height);
bool bs_pbuffer_clear(bs_pbuffer_t *pbuffer, sfColor color);
bool bs_pbuffer_set_pixel(bs_pbuffer_t *pbuffer, \
unsigned int x, unsigned int y, sfColor color);
bool bs_pbuffer_set_pos(bs_pbuffer_t *pbuffer, float pos_x, float pos_y);
bool bs_pbuffer_set_offset(bs_pbuffer_t *pbuffer, \
float offset_x, float offset_y);
bool bs_pbuffer_render(bs_frame_t *frame, bs_pbuffer_t *pbuffer);
bool bs_pbuffer_add_to_scene(bs_scene_t *scene, bs_pbuffer_t *pbuffer);
void bs_pbuffer_destroy(bs_pbuffer_t *pbuffer);
bs_pbuffer_t *bs_pbuffer_get_by_id(bs_scene_t *scene, char *id);
bool bs_pbuffer_set_layer(bs_pbuffer_t *pbuffer, short layer);

#endif /* !BS_PBUFFER_H_ */
