/*
** EPITECH PROJECT, 2018
** sprites_manager
** File description:
** sprites_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/*
    int left;
    int top;
    int width;
    int height;
*/

static sfIntRect determine_sprite_box(bs_sprite_anim_t *anim)
{
	sfIntRect box;

	box.left = (anim->is_vertical) ? anim->pos_a.x : anim->pos_a.x + \
	anim->size.x * anim->current_state;
	box.top = (anim->is_vertical) ? anim->pos_a.y + \
	anim->size.y * anim->current_state : anim->pos_a.y;
	box.height = anim->size.y;
	box.width = anim->size.x;
	return (box);
}

static bool handle_anim_states(bs_sprite_anim_t *anim)
{
	if (anim->stay_now == true) {
		return (true);
	}
	if (anim->curr_tick_delay >= anim->max_tick_delay) {
		anim->curr_state++;
		if (anim->curr_state >= anim->max_states) {
			anim->curr_state = 0;
			anim->is_finish = (anim->is_looped || anim->stay_on_last_frame) ? false : true;
			anim->stay_now = anim->stay_on_last_frame;
		}
	}
	anim->curr_tick_delay++;
}

bool bs_sprite_anim_render(bs_frame_t *frame, bs_sprite_t *sprite, \
bs_sprite_anim_t *anim)
{
	sfIntRect sprite_box = determine_sprite_box(anim);
	sfRenderStates render_state = bs_init_render_states();

	sfSprite_setPosition(anim->sprite, sprite->pos_s);
	sfSprite_setScale(anim->sprite, sprite->scale);
	sfSprite_setTexture(anim->sprite, anim->texture, sfTrue);
	sfSprite_setTextureRect(anim->sprite, sprite_box);
	sfRenderWindow_drawSprite(frame->window, anim->sprite, render_state);
	handle_anim_states(anim);
	return (true);
}


/*

static int render_sprite_2(frame_t *frame, sprite_info_t *sprite_inf)
{
	if (sprite_inf->curr_tick >= sprite_inf->tick_max) {
		if (++sprite_inf->current_state >= sprite_inf->total_states)
			sprite_inf->current_state = 0;
		sprite_inf->curr_tick = 0;
	}
	sprite_inf->curr_tick++;
	return (0);
}

int render_sprite(frame_t *frame, sprite_info_t *sprite_inf)
{
	sfIntRect rec = {sprite_inf->size.x * sprite_inf->current_state,
	sprite_inf->vertical_state * sprite_inf->size.y, sprite_inf->size.x, \
	sprite_inf->size.y};

	if (frame == NULL || sprite_inf == NULL || \
	sprite_inf->enabled == false)
		return (0);
	if (sprite_inf->is_init) {
		sfSprite_move(sprite_inf->sprite , sprite_inf->speed);
	} else {
		sfSprite_setPosition(sprite_inf->sprite , sprite_inf->pos);
		sprite_inf->is_init = 1;
	}
	sfSprite_setScale(sprite_inf->sprite, sprite_inf->scale);
	sfSprite_setTexture(sprite_inf->sprite, sprite_inf->texture, sfTrue);
	if (sprite_inf->size.x >= 0 && sprite_inf->size.y >= 0)
		sfSprite_setTextureRect(sprite_inf->sprite, rec);
	sfRenderWindow_drawSprite(frame->window, sprite_inf->sprite, NULL);
	return (render_sprite_2(frame, sprite_inf));
*/