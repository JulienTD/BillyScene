/*
** EPITECH PROJECT, 2018
** bs_components
** File description:
** All components
*/

#ifndef BS_COMPONENTS_H_
	#define BS_COMPONENTS_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_events.h"
#include <stdbool.h>

typedef enum bs_button_status_e
{
	NORMAL,
	HOVERED,
	CLICKED
} bs_button_status_t;

typedef struct bs_sound_s
{
	char *id_sound;
	sfSound *sound;
	sfSoundBuffer *buffer;
} bs_sound_t;

typedef enum bs_data_type_e
{
	BS_LIST,
	BS_PIXEL_BUFFER,
	BS_FRAME,
	BS_SCENE,
	BS_SPRITE_ANIM,
	BS_SPRITE,
	BS_LABEL,
	BS_TEXTFIELD,
	BS_BUTTON,
	BS_UNKNOW
} bs_data_type_t;

typedef struct bs_list_s
{
	int id;
	void *data;
	bs_data_type_t data_type;
	struct bs_list_s *next;
} bs_list_t;

typedef struct bs_pbuffer_s
{
	char *id_pbuffer;
	sfVector2f pos;
	sfVector2f offset;
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
	sfSprite *sprite;
	sfTexture *texture;
	sfRenderStates *rs;
} bs_pbuffer_t;

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

typedef struct bs_scene_s
{
	char *id_scene;
	bs_list_t *button_list;
	bs_list_t *sprite_list;
	bs_list_t *label_list;
	bs_list_t *textfield_list;
	bs_list_t *pbuffer_list;
	void (*event_key_pressed)(bs_event_key_pressed_t event);
	void (*event_mouse_pressed)(bs_event_mouse_pressed_t event);
	void (*event_mouse_released)(bs_event_mouse_released_t event);
	void (*event_mouse_moved)(bs_event_mouse_moved_t event);
	void (*event_mouse_wheel_scrolled)(bs_event_mouse_wheel_scrolled_t \
	event);
	void (*event_text_entered)(bs_event_text_entered_t event);
	void (*event_tick)(bs_event_tick_t event);
	void (*event_init)(bs_event_scene_init_t event);
	void (*event_init_post)(bs_event_scene_init_t event);
	int current_tick;
} bs_scene_t;

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

typedef struct bs_label_s
{
	char *id_label;
	sfText *text;
	sfFont *font;
	sfVector2f pos;
	sfVector2f offset;
	bool enabled;
	sfRenderStates *rs;
} bs_label_t;

typedef struct bs_textfield_s
{
	char *id_textfield;
	sfRectangleShape *rect;
	bs_label_t *label;
	sfTexture *texture;
	int max_length;
	int is_focus;
	sfVector2f pos;
	sfVector2f offset;
	bool enabled;
	void (*focus_event)(bs_event_textfield_focus_t event);
	void (*unfocus_event)(bs_event_textfield_unfocus_t event);
	_Bool (*text_entered_event)(bs_event_textfield_text_entered_t event);
	sfRenderStates *rs;
} bs_textfield_t;

typedef struct bs_button_s
{
	char *id_button;
	sfRectangleShape *rect;
	sfTexture *texture_base;
	sfTexture *texture_hover;
	sfTexture *texture_clicked;
	void (*click_pressed_event)(bs_event_button_click_pressed_t event);
	void (*click_released_event)(bs_event_button_click_released_t event);
	void (*hover_event)(bs_event_button_hover_t event);
	void (*hover_in_event)(bs_event_button_hover_in_t event);
	void (*hover_out_event)(bs_event_button_hover_out_t event);
	bs_sound_t *sound_click;
	bs_sound_t *sound_hover_in;
	bs_sound_t *sound_hover_out;
	bs_button_status_t status;
	int texture_status;
	sfVector2f pos;
	sfVector2f offset;
	bool enabled;
	sfRenderStates *rs;
} bs_button_t;

typedef struct bs_panel_s
{
	bs_scene_t *parent;
	char *id_panel;
	bs_list_t *button_list;
	bs_list_t *sprite_list;
	bs_list_t *label_list;
	bs_list_t *textfield_list;
	bs_list_t *pbuffer_list;
	void (*event_key_pressed)(bs_event_key_pressed_t event);
	void (*event_mouse_pressed)(bs_event_mouse_pressed_t event);
	void (*event_mouse_released)(bs_event_mouse_released_t event);
	void (*event_mouse_moved)(bs_event_mouse_moved_t event);
	void (*event_mouse_wheel_scrolled)(bs_event_mouse_wheel_scrolled_t \
	event);
	void (*event_text_entered)(bs_event_text_entered_t event);
	void (*event_tick)(bs_event_tick_t event);
	void (*event_init)(bs_event_scene_init_t event);
	void (*event_init_post)(bs_event_scene_init_t event);
	int current_tick;
} bs_panel_t;

#endif /* !BS_COMPONENTS_H_ */
