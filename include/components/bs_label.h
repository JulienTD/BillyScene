/*
** EPITECH PROJECT, 2019
** BillyScene
** File description:
** bs_label
*/

#ifndef BS_LABEL_H_
    #define BS_LABEL_H_

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "components/bs_frame.h"
#include "components/bs_label.h"
#include "components/bs_scene.h"

typedef struct bs_label_s
{
    char *id_label;
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfVector2f offset;
    short layer;
    bool enabled;
    sfRenderStates *rs;
    void (*event_key_pressed)(bs_event_key_pressed_t event);
    void (*event_mouse_pressed)(bs_event_mouse_pressed_t event);
    void (*event_mouse_released)(bs_event_mouse_released_t event);
    void (*event_mouse_moved)(bs_event_mouse_moved_t event);
    void (*event_mouse_wheel_scrolled)(bs_event_mouse_wheel_scrolled_t \
    event);
    void (*event_text_entered)(bs_event_text_entered_t event);
} bs_label_t;


/*    PROTOTYPES    */
bs_label_t *bs_label_create(char *id, char *font, char *text, int font_size);
bool bs_label_render(bs_frame_t *frame, bs_label_t *label);
bool bs_label_add_to_scene(bs_scene_t *scene, bs_label_t *label);
bool bs_label_set_pos(bs_label_t *label, float pos_x, float pos_y);
bool bs_label_set_offset(bs_label_t *label, float offset_x, float offset_y);
bool bs_label_set_str(bs_label_t *label, char *str);
char *bs_label_get_str(bs_label_t *label);
void bs_label_destroy(bs_label_t *label);
bs_label_t *bs_label_get_by_id(bs_scene_t *scene, char *id);
bool bs_label_set_color(bs_label_t *label, sfColor color);
bool bs_label_set_layer(bs_label_t *label, short layer);
bool bs_label_mouse_moved_manager(sfMouseMoveEvent evt, bs_frame_t *frame, \
bs_scene_t *scene, bs_label_t *label);
bool bs_label_mouse_pressed_manager(sfMouseButtonEvent evt, \
bs_frame_t *frame, bs_scene_t *scene, bs_label_t *label);
bool bs_label_mouse_released_manager(sfMouseButtonEvent evt, \
bs_frame_t *frame, bs_scene_t *scene, bs_label_t *label);
bool bs_label_key_pressed_manager(sfKeyEvent evt, bs_frame_t *frame, \
bs_scene_t *scene, bs_label_t *label);
bool bs_label_mouse_wheel_scrolled_manager(sfMouseWheelScrollEvent evt, \
bs_frame_t *frame, bs_scene_t *scene, bs_label_t *label);
bool bs_label_text_entered_manager(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene, bs_label_t *label);
#endif /* !BS_LABEL_H_ */
