/*
** EPITECH PROJECT, 2018
** render_sprite
** File description:
** render_sprite
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Draws sprite if it has no animation
 * 
 * @param frame 
 * @param sprite 
 * @return true 
 * @return false 
 */
static bool draw_sprite(bs_frame_t *frame, bs_sprite_t *sprite)
{
	sfIntRect sprite_box = {.width = sprite->size.x, \
	.height = sprite->size.y, .left = sprite->pos_s.x, \
	.top = sprite->pos_s.y};
	sfRenderStates *render_states = bs_init_render_states();

	sfSprite_setScale(sprite->sprite, sprite->scale);
	sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
	if (sprite->size.x >= 0 && sprite->size.y >= 0) {
		sfSprite_setTextureRect(sprite->sprite, sprite_box);
	}
	sfRenderWindow_drawSprite(frame->window, sprite->sprite, render_states);
	free(render_states);
	return true;
}

/**
 * @brief Updates the sprite's position
 * (Sets its position if it's not init or moves it directly)
 * 
 * @param sprite 
 * @return true 
 * @return false 
 */
static bool update_sprite_position(bs_sprite_t *sprite)
{
	if (sprite->is_init == false) {
		sfSprite_setPosition(sprite->sprite, sprite->pos);
		sprite->is_init = true;
	} else {
		sfSprite_move(sprite->sprite, sprite->speed);
	}
	return true;
}

/**
 * @brief Renders a sprite
 * 
 * @param frame 
 * @param sprite 
 * @return true 
 * @return false 
 */
bool bs_sprite_render(bs_frame_t *frame, bs_sprite_t *sprite)
{
	bs_sprite_anim_t *anim = NULL;

	if (frame == NULL || sprite == NULL || sprite->enabled == false)
		return (0);
	update_sprite_position(sprite);
	anim = bs_sprite_anim_get_active(sprite);
	if (anim == NULL) {
		anim = bs_sprite_anim_get_default(sprite);
		if (anim == NULL) {
			draw_sprite(frame, sprite);
		} else {
			bs_sprite_anim_render(frame, sprite, anim);
		}
		return (true); 
	}
	bs_sprite_anim_render(frame, sprite, anim);
	return (true);
}
