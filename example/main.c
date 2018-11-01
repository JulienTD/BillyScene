/*
** EPITECH PROJECT, 2017
** frame
** File description:
** frame
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"
#include "bs_prototypes.h"

void scene_tick(bs_event_tick_t event);
void click_buton(bs_event_button_click_pressed_t event);
void hover_button_in(bs_event_button_hover_in_t event);
void hover_button_out(bs_event_button_hover_out_t event);
void hover_button(bs_event_button_hover_t event);

bs_frame_t *init(int width, int height)
{
	bs_frame_t *frame = bs_frame_create();
	sfVideoMode mode = {width, height, 32};

	if (frame == NULL)
		return (NULL);
	frame->width = width;
	frame->height = height;
	frame->window = sfRenderWindow_create(mode, "Billy Scene", \
	sfClose, NULL);
	frame->clock = sfClock_create();
	sfRenderWindow_setFramerateLimit(frame->window, 60);
	return (frame);
}

void game_loop(bs_frame_t *frame)
{
	bs_scene_t *scene = bs_scene_get_by_id(frame, frame->current_scene);

	if (frame == NULL)
		return;
	sfRenderWindow_clear(frame->window, sfBlack);
	bs_scene_render(scene, frame);
	sfRenderWindow_display(frame->window);
	sfClock_restart(frame->clock);
}

void scene_tick(bs_event_tick_t event)
{

}

void click_buton(bs_event_button_click_pressed_t event)
{
	bs_sprite_t *sprite = bs_sprite_get_by_id(event.scene, "test");

	if (sprite == NULL)
		return;
	bs_sprite_anim_play(sprite, "anim_test", false);
}

void hover_button_in(bs_event_button_hover_in_t event)
{
	sfRectangleShape_setOutlineThickness(event.button->rect, 10.0);
}

void hover_button_out(bs_event_button_hover_out_t event)
{
	sfRectangleShape_setOutlineThickness(event.button->rect, 0.0);
}

void hover_button(bs_event_button_hover_t event)
{

}

void scene_key_manager(bs_event_key_pressed_t event)
{
	if (event.event.code == sfKeyEscape) {
		sfRenderWindow_close(event.frame->window);
	}
}

void display_frame(int width, int height)
{
	bs_frame_t *frame = init(width, height);

	if (frame == NULL)
		return;
	bs_scene_t *scene = bs_scene_create("intro");

	bs_button_t *button = bs_button_create("button", 200, 100);

	scene->event_key_pressed = &scene_key_manager;
	button->click_pressed_event = &click_buton;
	button->hover_in_event = &hover_button_in;
	button->hover_out_event = &hover_button_out;
	button->hover_event = &hover_button;
	bs_button_set_sound_click(button, "./example/res/button_sound.ogg");
	bs_button_set_sound_hover_in(button, "./example/res/button_sound.ogg");
	bs_button_set_sound_hover_out(button, "./example/res/button_sound.ogg");
	
	bs_button_set_base_texture(button, "./example/res/button_normal.jpg");
	bs_button_set_hover_texture(button, "./example/res/button_hover.jpg");
	bs_button_set_clicked_texture(button, "./example/res/button_click.jpg");

	bs_button_set_pos(button, 20.0, 20.0);
	bs_button_add_to_scene(scene, button);


	bs_sprite_t *sprite = bs_sprite_create("test", "./example/res/sprite_list.png");

	bs_sprite_set_pos(sprite, 400, 200);
	bs_sprite_set_size(sprite, 100, 100);
	sprite->pos_s.x = 0;
	sprite->pos_s.y = 100;
	bs_sprite_anim_t *anim = bs_sprite_anim_create("anim_test", "./example/res/sprite_list.png", 100, 100);
	
	anim->max_states = 6;
	anim->max_tick_delay = 20;
	anim->is_vertical = false;
	anim->stay_on_last_frame = true;
	anim->is_looped = false;
	anim->is_default = false;
	bs_sprite_anim_add(sprite, anim);
	bs_sprite_add_to_scene(scene, sprite);
	bs_sprite_anim_play(sprite, "anim_test", false);
	scene->event_tick = &scene_tick;
	bs_scene_add_to_frame(frame, scene);
	bs_scene_set_to(frame, "intro");
	bs_label_t *label = bs_label_create("./example/res/font.ttf", "yo", 20);

	bs_label_add_to_scene(scene, label);
	bs_label_set_pos(label, 500, 500);
	bs_textfield_t *textfield = bs_textfield_create("textfield", "./example/res/font.ttf", 400, 100);
	bs_textfield_set_focus(textfield, true);
	bs_textfield_add_to_scene(scene, textfield);
	sfText_setCharacterSize(textfield->label->text, 30);
	while (sfRenderWindow_isOpen(frame->window)) {
		while (sfRenderWindow_pollEvent(frame->window, \
		&(frame->event)))
			bs_event_dispatcher(frame->event, frame);
		if (sfClock_getElapsedTime(frame->clock).microseconds \
		>= 50000) {
			game_loop(frame);
		}
	}
	bs_frame_destroy(frame);
}

int main(void)
{
	display_frame(1000, 1000);
}