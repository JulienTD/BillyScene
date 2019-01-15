/*
** EPITECH PROJECT, 2019
** BillyScene
** File description:
** bs_sprite
*/

#ifndef BS_SPRITE_H_
    #define BS_SPRITE_H_

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "components/bs_list.h"

typedef struct bs_sprite_anim_s
{
    char *id_anim;
    sfVector2f size;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos_s;
    sfVector2f pos_a;
    bool is_vertical;
    int max_states;
    int curr_state;
    int max_tick_delay;
    int curr_tick_delay;
    bool stay_on_last_frame;
    bool stay_now;
    bool is_looped;
    bool is_finish;
    bool is_default;
    bool reverse;
    sfRenderStates *rs;
} bs_sprite_anim_t;

typedef struct bs_sprite_s
{
    char *id_sprite;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i size;
    sfVector2f offset;
    sfVector2f pos;
    sfVector2f pos_s;
    sfVector2f scale;
    sfVector2f speed;
    bool is_init;
    bool enabled;
    char *curr_anim;
    bs_list_t *anims;
    sfRenderStates *rs;
} bs_sprite_t;

/*    PROTOTYPES    */

/* Prototypes to manipulates sprites */
bool bs_sprite_add_to_scene(bs_scene_t *scene, bs_sprite_t *sprite);
bs_sprite_t *bs_sprite_create(char *id, const char *texture_path);
bs_sprite_t *bs_sprite_get_by_id(bs_scene_t *scene, char *id);
bool bs_sprite_render(bs_frame_t *frame, bs_sprite_t *sprite);
bool bs_sprite_set_pos(bs_sprite_t *sprite, float x, float y);
bool bs_sprite_set_offset(bs_sprite_t *sprite, \
float offset_x, float offset_y);
bool bs_sprite_set_scale(bs_sprite_t *sprite, float x, float y);
bool bs_sprite_set_size(bs_sprite_t *sprite, int x, int y);
bool bs_sprite_set_speed(bs_sprite_t *sprite, float x, float y);
void bs_sprite_destroy(bs_sprite_t *sprite);


/* Prototypes to manipulates sprites animations */
bool bs_sprite_anim_add(bs_sprite_t *sprite, bs_sprite_anim_t *anim);
bs_sprite_anim_t *bs_sprite_anim_create(char *id, char *path, \
float height, float width);
bs_sprite_anim_t *bs_sprite_anim_get_active(bs_sprite_t *sprite);
bs_sprite_anim_t *bs_sprite_anim_get_by_id(bs_sprite_t *sprite, char *id);
bs_sprite_anim_t *bs_sprite_anim_get_default(bs_sprite_t *sprite);
bs_sprite_anim_t *bs_sprite_anim_play(bs_sprite_t *sprite, char *id, \
bool reverse);
bool bs_sprite_anim_render(bs_frame_t *frame, bs_sprite_t *sprite, \
bs_sprite_anim_t *anim);
bool bs_sprite_anim_stop(bs_sprite_t *sprite);
void bs_sprite_anim_destroy(bs_sprite_anim_t *anim);
#endif /* !BS_SPRITE_H_ */
