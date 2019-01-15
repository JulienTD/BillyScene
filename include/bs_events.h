/*
** EPITECH PROJECT, 2018
** bs_events
** File description:
** Components event structure
*/

#ifndef BS_EVENTS_H_
    #define BS_EVENTS_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#include "components/bs_button.h"
#include "components/bs_frame.h"
#include "components/bs_label.h"
#include "components/bs_list.h"
#include "components/bs_pbuffer.h"
#include "components/bs_scene.h"
#include "components/bs_sound.h"
#include "components/bs_sprite.h"
#include "components/bs_textfield.h"
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

/*   SCENE EVENTS   */
// typedef struct bs_event_key_pressed_s
// {
//     sfKeyEvent event;
//     struct bs_frame_s *frame;
//     struct bs_scene_s *scene;
// } bs_event_key_pressed_t;

// typedef struct bs_event_mouse_pressed_s
// {
//     sfMouseButtonEvent event;
//     struct bs_frame_s *frame;
//     struct bs_scene_s *scene;
// } bs_event_mouse_pressed_t;

// typedef struct bs_event_mouse_released_s
// {
//     sfMouseButtonEvent event;
//     struct bs_frame_s *frame;
//     struct bs_scene_s *scene;
// } bs_event_mouse_released_t;

// typedef struct bs_event_mouse_moved_s
// {
//     sfMouseMoveEvent event; 
//     struct bs_frame_s *frame;
//     struct bs_scene_s *scene;
// } bs_event_mouse_moved_t;

// typedef struct bs_event_mouse_wheel_scrolled_s
// {
//     sfMouseWheelScrollEvent event;
//     struct bs_frame_s *frame;
//     struct bs_scene_s *scene;
// } bs_event_mouse_wheel_scrolled_t;

// typedef struct bs_event_text_entered_s
// {
//     sfTextEvent event;
//     struct bs_frame_s *frame;
//     struct bs_scene_s *scene;

// }bs_event_text_entered_t;

// typedef struct bs_event_tick_s
// {
//     struct bs_frame_s *frame;
//     struct bs_scene_s *scene;
// } bs_event_tick_t;

// typedef struct bs_event_scene_init_s
// {
//     struct bs_frame_s *frame;
//     struct bs_scene_s *scene;
// } bs_event_scene_init_t;

/*   BUTTON EVENTS   */
// typedef struct bs_event_button_click_pressed_s
// {
//     sfMouseButtonEvent event;
//     struct bs_frame_s *frame;
//     struct bs_button_s *button;
//     struct bs_scene_s *scene;
// } bs_event_button_click_pressed_t;

// typedef struct bs_event_button_click_released_s
// {
//     sfMouseButtonEvent event;
//     struct bs_frame_s *frame;
//     struct bs_button_s *button;
//     struct bs_scene_s *scene;
// } bs_event_button_click_released_t;

// typedef struct bs_event_button_hover_s
// {
//     sfMouseMoveEvent event;
//     struct bs_frame_s *frame;
//     struct bs_button_s *button;
//     struct bs_scene_s *scene;
// } bs_event_button_hover_t;

// typedef struct bs_event_button_hover_in_s
// {
//     sfMouseMoveEvent event;
//     struct bs_frame_s *frame;
//     struct bs_button_s *button;
//     struct bs_scene_s *scene;
// } bs_event_button_hover_in_t;

// typedef struct bs_event_button_hover_out_s
// {
//     sfMouseMoveEvent event;
//     struct bs_frame_s *frame;
//     struct bs_button_s *button;
//     struct bs_scene_s *scene;
// } bs_event_button_hover_out_t;

/*   TEXTFIELD EVENTS   */
// typedef struct bs_event_textfield_focus_s
// {
//     sfMouseButtonEvent event;
//     struct bs_frame_s *frame;
//     struct bs_textfield_s *textfield;
//     struct bs_scene_s *scene;
// } bs_event_textfield_focus_t;

// typedef struct bs_event_textfield_unfocus_s
// {
//     sfMouseButtonEvent event;
//     struct bs_frame_s *frame;
//     struct bs_textfield_s *textfield;
//     struct bs_scene_s *scene;
// } bs_event_textfield_unfocus_t;

// typedef struct bs_event_textfield_text_entered_s
// {
//     sfTextEvent event;
//     struct bs_frame_s *frame;
//     struct bs_textfield_s *textfield;
//     struct bs_scene_s *scene;
// } bs_event_textfield_text_entered_t;


#endif /* !BS_EVENTS_H_ */
