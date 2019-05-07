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
void textfield_unfocus(bs_event_textfield_unfocus_t event);
void textfield_focus(bs_event_textfield_focus_t event);
void mouse_move(bs_event_mouse_moved_t event);

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
	bs_scene_t *scene = event.scene;
	bs_sprite_t *sprite = bs_sprite_get_by_id(scene, "test");
	static mult = 1;
	if (sprite == NULL)
		return;
	sfVector2f real_pos = sfSprite_getPosition(sprite->sprite);

	if (sprite == NULL || scene->current_tick != 20)
		return;
	if (real_pos.x + sprite->size.x + (5 * mult) > event.frame->width) {
		mult *= -1;
	}
	if (real_pos.x + (5 * mult) < 0) {
		mult *= -1;
	}
	sprite->speed.x = 5 * mult;
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
	bs_button_t *button = event.button;

	bs_button_set_offset(button, 0, button->offset.y + 10);
}

void label_key_manager(bs_event_key_pressed_t event)
{
	printf("Label key\n");
}

void scene_key_manager(bs_event_key_pressed_t event)
{
	if (event.event.code == sfKeyEscape) {
		sfRenderWindow_close(event.frame->window);
	}
}

void textfield_unfocus(bs_event_textfield_unfocus_t event)
{
	bs_textfield_t *tf = event.textfield;

	sfRectangleShape_setFillColor(tf->rect, sfWhite);
	sfRectangleShape_setOutlineThickness(tf->rect, 0);
}

void textfield_focus(bs_event_textfield_focus_t event)
{
	bs_textfield_t *tf = event.textfield;

	sfRectangleShape_setFillColor(tf->rect, sfGreen);
	sfRectangleShape_setOutlineThickness(tf->rect, 10);
}

void label_mouse_moved(bs_event_mouse_moved_t event)
{
	printf("test\n");
}

void mouse_move(bs_event_mouse_moved_t event)
{
	bs_scene_t *scene = event.scene;
	bs_frame_t *frame = event.frame;
	bs_pbuffer_t *pbuffer = bs_pbuffer_get_by_id(scene, "test");

	if (pbuffer == NULL)
		return;
	bs_pbuffer_set_pixel(pbuffer, event.event.x - pbuffer->pos.x, \
	event.event.y - pbuffer->pos.y, sfRed);
	bs_pbuffer_set_pixel(pbuffer, event.event.x + 1 - pbuffer->pos.x, \
	event.event.y - pbuffer->pos.y, sfRed);
	bs_pbuffer_set_pixel(pbuffer, event.event.x - pbuffer->pos.x, \
	event.event.y + 1 - pbuffer->pos.y, sfRed);
	bs_pbuffer_set_pixel(pbuffer, event.event.x + 1 - pbuffer->pos.x, \
	event.event.y + 1 - pbuffer->pos.y, sfRed);
}

void display_frame(int width, int height)
{
	bs_frame_t *frame = init(width, height);

	if (frame == NULL)
		return;
	// bs_frame_t *second_win = init(500, 200);

	bs_scene_t *scene = bs_scene_create("intro");

	// bs_button_t *button = bs_button_create("button", 100, 100);
	// bs_button_t *button1 = bs_button_create("button1", 100, 100);
	// bs_button_t *button2 = bs_button_create("button2", 100, 100);

	// bs_button_set_pos(button, 10, 10);
	// bs_button_set_pos(button1, 80, 10);
	// bs_button_set_pos(button2, 140, 10);
	
	// bs_button_set_base_clicked_hover_texture(button, "./example/res/button_normal.jpg");
	// bs_button_set_base_clicked_hover_texture(button1, "./example/res/button_hover.jpg");
	// bs_button_set_base_clicked_hover_texture(button2, "./example/res/button_click.jpg");

	// bs_button_set_layer(button, 0);
	// bs_button_set_layer(button1, 3);
	// bs_button_set_layer(button2, 2);

	// bs_button_add_to_scene(scene, button);
	// bs_button_add_to_scene(scene, button1);
	// bs_button_add_to_scene(scene, button2);

	// bs_scene_add_to_frame(frame, scene);
	// bs_scene_set_to(frame, "intro");
	// bs_scene_refresh(scene);
	//////////////////
	bs_button_t *button = bs_button_create("button", 200, 100);

	scene->event_key_pressed = &scene_key_manager;
	button->click_pressed_event = &click_buton;
	button->hover_in_event = &hover_button_in;
	button->hover_out_event = &hover_button_out;
	button->hover_event = &hover_button;
	bs_button_set_sound_click(button, "./example/res/button_sound.ogg");
	bs_button_set_sound_hover_in(button, "./example/res/button_sound.ogg");
	bs_button_set_sound_hover_out(button, "./example/res/button_sound.ogg");
	
	bs_button_set_texture_base(button, "./example/res/button_normal.jpg");
	bs_button_set_texture_hover(button, "./example/res/button_hover.jpg");
	bs_button_set_texture_clicked(button, "./example/res/button_click.jpg");

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
	anim->is_looped = true;
	anim->is_default = true;
	bs_sprite_anim_add(sprite, anim);
	bs_sprite_add_to_scene(scene, sprite);
	// bs_sprite_anim_play(sprite, "anim_test", false);
	scene->event_tick = &scene_tick;
	bs_scene_add_to_frame(frame, scene);
	bs_scene_set_to(frame, "intro");
	bs_label_t *label = bs_label_create("test", "./example/res/font.ttf", "je suis le str", 22);
	bs_label_set_color(label, sfYellow);
	bs_label_add_to_scene(scene, label);
	bs_label_set_pos(label, 100, 100);
	label->event_key_pressed = &label_key_manager;
	label->event_mouse_moved = &label_mouse_moved;
	bs_textfield_t *textfield = bs_textfield_create("textfield", "./example/res/font.ttf", 400, 100);
	sfText_setCharacterSize(textfield->label->text, 30);
	textfield->focus_event = &textfield_focus;
	textfield->unfocus_event = &textfield_unfocus;
	bs_textfield_set_focus(textfield, true);
	// bs_textfield_set_max_length(textfield, 100);
	bs_textfield_add_to_scene(scene, textfield);
	bs_textfield_set_pos(textfield, 500, 500);
	bs_pbuffer_t *pbuffer = bs_pbuffer_create("test", 500, 500);
	bs_pbuffer_set_pos(pbuffer, 200, 100);
	// bs_pbuffer_add_to_scene(scene, pbuffer);
	scene->event_mouse_moved = &mouse_move;
	bs_frame_set_cursor(frame, "./example/res/button_click.jpg");
	while (sfRenderWindow_isOpen(frame->window)) {
		while (sfRenderWindow_pollEvent(frame->window, \
		&(frame->event)))
			bs_event_dispatcher(frame->event, frame);
		if (sfClock_getElapsedTime(frame->clock).microseconds \
		>= 50000) {
			game_loop(frame);
			//game_loop(second_win);
		}
	}
	bs_frame_destroy(frame);
}

int main(void)
{
	display_frame(1000, 1000);
}