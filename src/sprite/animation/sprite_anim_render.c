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
	anim->size.x * anim->curr_state;
	box.top = (anim->is_vertical) ? anim->pos_a.y + \
	anim->size.y * anim->curr_state : anim->pos_a.y;
	box.height = anim->size.y;
	box.width = anim->size.x;
	if (anim->reverse && anim->is_vertical) {
		box.top = box.height * anim->max_states - box.top;
	} else if (anim->reverse && !anim->is_vertical) {
		box.left = box.width * anim->max_states - box.left;
	}
	return (box);
}

static bool handle_anim_states(bs_sprite_anim_t *anim)
{
	if (anim->curr_state >= anim->max_states) {
		if (anim->is_looped || anim->stay_on_last_frame) {
			anim->is_finish = false;
		} else {
			anim->is_finish = true;
		}
		anim->stay_now = anim->stay_on_last_frame;
		anim->curr_state = (anim->stay_now) ? anim->max_states : 0;
		return (true);
	}
	anim->curr_state++;
	return (true);
}

static bool tick_anim(bs_sprite_anim_t *anim)
{
	if (anim->stay_now == true) {
		anim->curr_tick_delay = 0;
		return (true);
	}
	if (anim->curr_tick_delay >= anim->max_tick_delay) {
		anim->curr_tick_delay = 0;
		handle_anim_states(anim);
	}
	anim->curr_tick_delay++;
	return (true);
}

bool bs_sprite_anim_render(bs_frame_t *frame, bs_sprite_t *sprite, \
bs_sprite_anim_t *anim)
{
	sfIntRect sprite_box = determine_sprite_box(anim);
	sfRenderStates *render_state = bs_init_render_states();
	sfVector2f sprite_pos = sfSprite_getPosition(sprite->sprite);

	sfSprite_setPosition(anim->sprite, sprite_pos);
	sfSprite_setScale(anim->sprite, sprite->scale);
	sfSprite_setTexture(anim->sprite, anim->texture, sfTrue);
	sfSprite_setTextureRect(anim->sprite, sprite_box);
	sfRenderWindow_drawSprite(frame->window, anim->sprite, render_state);
	tick_anim(anim);
	free(render_state);
	return (true);
}
