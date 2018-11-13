/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** bs_prototypes
*/

#ifndef BS_PROTOTYPES_H_
	#define BS_PROTOTYPES_H_
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bs_components.h"

/* Prototypes to manipulate buttons */
bool bs_button_add_to_scene(bs_scene_t *scene, bs_button_t *button);
bs_button_t *bs_button_create(char *id, float width, float heigth);
void bs_button_destroy(bs_button_t *button);
bool bs_is_mouse_on_button(bs_button_t button, float clickX, float clickY);
int bs_button_render(bs_frame_t *frame, bs_button_t *button);
int bs_button_set_base_clicked_hover_texture(bs_button_t *button, char *path);
int bs_button_set_base_texture(bs_button_t *button, char *path);
int bs_button_set_clicked_texture(bs_button_t *button, char *path);
int bs_button_set_hover_texture(bs_button_t *button, char *path);
bool bs_button_set_pos(bs_button_t *button, float pos_x, float pos_y);
bool bs_button_set_size(bs_button_t *button, float width, float height);
bool bs_button_set_sound_click(bs_button_t *button, char *path);
bool bs_button_set_sound_hover_in(bs_button_t *button, char *path);
bool bs_button_set_sound_hover_out(bs_button_t *button, char *path);
bs_button_t *bs_button_get_by_id(bs_scene_t *scene, char *id);


/* Prototypes of the file event_dispatcher.c */
void bs_event_dispatcher(sfEvent event, bs_frame_t *frame);


/* Prototypes to manipulate button events */
void bs_button_mouse_move_manager(sfMouseMoveEvent evt, bs_frame_t *frame, \
bs_scene_t *scene);
void bs_button_mouse_pressed_manager(sfMouseButtonEvent event, \
bs_frame_t *frame, bs_scene_t *scene);
void bs_button_mouse_released_manager(sfMouseButtonEvent event, \
bs_frame_t *frame, bs_scene_t *scene);


/* Prototypes to manipulate general events */
void bs_general_key_pressed_manager(sfKeyEvent event, bs_frame_t *frame, \
bs_scene_t *scene);


/* Prototypes to manipulate scene events */
bool bs_scene_key_pressed_manager(sfKeyEvent evt, bs_frame_t *frame, \
bs_scene_t *scene);
bool bs_scene_mouse_moved_manager(sfMouseMoveEvent evt, bs_frame_t *frame, \
bs_scene_t *scene);
bool bs_scene_mouse_pressed_manager(sfMouseButtonEvent evt, \
bs_frame_t *frame, bs_scene_t *scene);
bool bs_scene_mouse_released_manager(sfMouseButtonEvent evt, \
bs_frame_t *frame, bs_scene_t *scene);
bool bs_scene_mouse_wheel_scrolled_manager(sfMouseWheelScrollEvent evt, \
bs_frame_t *frame, bs_scene_t *scene);
bool bs_scene_text_entered_manager(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene);

/* Prototypes to manipulate textfield events */
bool bs_textfield_text_entered_manager(bs_textfield_t *textfield, \
sfTextEvent evt, bs_frame_t *frame, bs_scene_t *scene);
void bs_textfield_mouse_pressed_manager(sfMouseButtonEvent event, \
bs_frame_t *frame, bs_scene_t *scene);

/* Prototypes to manipulate frames */
bs_frame_t *bs_frame_create(void);
void bs_frame_destroy(bs_frame_t *frame);


/* Prototypes to manipulate lists */
bs_list_t *bs_list_create(void *data);
bool bs_list_delete(bs_list_t **head, int id);
bs_list_t *bs_list_get_by_id(bs_list_t **head, int id);
int bs_list_length(bs_list_t **head);
bs_list_t *bs_list_push(bs_list_t **head, void *data);
void bs_list_destroy(bs_list_t **head, void (*destroy)(void *data));
bool bs_list_each(bs_list_t **head, bool (*func_each)(void *data));


/* Prototypes to manipulates scenes */
bool bs_scene_add_to_frame(bs_frame_t *frame, bs_scene_t *scene);
bs_scene_t *bs_scene_create(char *id);
bs_scene_t *bs_scene_get_by_id(bs_frame_t *frame, char *id);
bool bs_scene_render_all_buttons(bs_scene_t *scene, bs_frame_t *frame);
bool bs_scene_render_all_labels(bs_scene_t *scene, bs_frame_t *frame);
bool bs_scene_render_all_sprites(bs_scene_t *scene, bs_frame_t *frame);
bool bs_scene_render_all_textfields(bs_scene_t *scene, bs_frame_t *frame);
bool bs_scene_render(bs_scene_t *scene, bs_frame_t *frame);
bool bs_scene_set_to(bs_frame_t *frame, char *id);
void bs_scene_destroy(bs_scene_t *scene);


/* Prototypes to manipulates sounds */
bs_sound_t *bs_sound_create(char *path);
bool bs_sound_play(bs_sound_t *sound);
bool bs_sound_set_new(bs_sound_t *sound, char *path);
void bs_sound_destroy(bs_sound_t *sound);

/* Prototypes to manipulates sprites */
bool bs_sprite_add_to_scene(bs_scene_t *scene, bs_sprite_t *sprite);
bs_sprite_t *bs_sprite_create(char *id, const char *texture_path);
bs_sprite_t *bs_sprite_get_by_id(bs_scene_t *scene, char *id);
bool bs_sprite_render(bs_frame_t *frame, bs_sprite_t *sprite);
bool bs_sprite_set_pos(bs_sprite_t *sprite, float x, float y);
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


/* Prototypes to manipulates labels */
bs_label_t *bs_label_create(char *id, char *font, char *text, int font_size);
int bs_label_render(bs_frame_t *frame, bs_label_t *label);
bool bs_label_add_to_scene(bs_scene_t *scene, bs_label_t *label);
bool bs_label_set_pos(bs_label_t *label, float pos_x, float pos_y);
bool bs_label_set_str(bs_label_t *label, char *str);
char *bs_label_get_str(bs_label_t *label);
void bs_label_destroy(bs_label_t *label);
bs_label_t *bs_label_get_by_id(bs_scene_t *scene, char *id);
bool bs_label_set_color(bs_label_t *label, sfColor color);


/* Prototypes to manipulates textfields */
bs_textfield_t *bs_textfield_create(char *id, char *font_path, float width, \
float height);
bool bs_textfield_render(bs_frame_t *frame, bs_textfield_t *textfield);
bool bs_textfield_set_focus(bs_textfield_t *textfield, bool is_focus);
bool bs_textfield_add_to_scene(bs_scene_t *scene, bs_textfield_t *textfield);
void bs_textfield_destroy(bs_textfield_t *textfield);
bs_textfield_t *bs_textfield_get_by_id(bs_scene_t *scene, char *id);
bool bs_is_mouse_on_textfield(bs_textfield_t textfield, \
float clickX, float clickY);
bool bs_textfield_set_max_length(bs_textfield_t *textfield, int max_length);


/* Prototypes to manipulates pixelbuffers */
bs_pbuffer_t *bs_pbuffer_create(char *id, unsigned int width, \
unsigned int height);
bool bs_pbuffer_clear(bs_pbuffer_t *pbuffer, sfColor color);
bool bs_pbuffer_set_pixel(bs_pbuffer_t *pbuffer, \
unsigned int x, unsigned int y, sfColor color);
bool bs_pbuffer_set_pos(bs_pbuffer_t *pbuffer, int pos_x, int pos_y);
bool bs_pbuffer_render(bs_frame_t *frame, bs_pbuffer_t *pbuffer);
bool bs_pbuffer_add_to_scene(bs_scene_t *scene, bs_pbuffer_t *pbuffer);
void bs_pbuffer_destroy(bs_pbuffer_t *pbuffer);
bs_pbuffer_t *bs_pbuffer_get_by_id(bs_scene_t *scene, char *id);


/* Prototypes of the file bs_set_str_to.c */
char *bs_set_str_to(char *src, char *new_str);

/* Prototypes of the file bs_str_are_equals.c */
bool bs_str_are_equals(char *str_1, char *str_2);

/* Prototypes of the file bs_strcpy.c */
char *bs_strcpy(char *src, char *dest);

/* Prototypes of the file bs_strlen.c */
int bs_strlen(char *str);

/* Prototypes of the file bs_init_render_states.c */
sfRenderStates *bs_init_render_states(void);

#endif /* !BS_PROTOTYPES_H_ */
