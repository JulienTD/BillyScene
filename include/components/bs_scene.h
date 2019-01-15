/*
** EPITECH PROJECT, 2019
** BillyScene
** File description:
** bs_scene_
*/

#ifndef BS_SCENE__H_
    #define BS_SCENE__H_

#include "components/bs_list.h"
#include "bs_events.h"

/*    EVENTS    */
typedef struct bs_event_key_pressed_s
{
    sfKeyEvent event;
    struct bs_frame_s *frame;
    struct bs_scene_s *scene;
} bs_event_key_pressed_t;

typedef struct bs_event_mouse_pressed_s
{
    sfMouseButtonEvent event;
    struct bs_frame_s *frame;
    struct bs_scene_s *scene;
} bs_event_mouse_pressed_t;

typedef struct bs_event_mouse_released_s
{
    sfMouseButtonEvent event;
    struct bs_frame_s *frame;
    struct bs_scene_s *scene;
} bs_event_mouse_released_t;

typedef struct bs_event_mouse_moved_s
{
    sfMouseMoveEvent event; 
    struct bs_frame_s *frame;
    struct bs_scene_s *scene;
} bs_event_mouse_moved_t;

typedef struct bs_event_mouse_wheel_scrolled_s
{
    sfMouseWheelScrollEvent event;
    struct bs_frame_s *frame;
    struct bs_scene_s *scene;
} bs_event_mouse_wheel_scrolled_t;

typedef struct bs_event_text_entered_s
{
    sfTextEvent event;
    struct bs_frame_s *frame;
    struct bs_scene_s *scene;

}bs_event_text_entered_t;

typedef struct bs_event_tick_s
{
    struct bs_frame_s *frame;
    struct bs_scene_s *scene;
} bs_event_tick_t;

typedef struct bs_event_scene_init_s
{
    struct bs_frame_s *frame;
    struct bs_scene_s *scene;
} bs_event_scene_init_t;

/*    COMPONENT    */

typedef struct bs_scene_s
{
    char *id_scene;
    bs_list_t *components_list;
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

/*    PROTOTYPES    */
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

#endif /* !BS_SCENE__H_ */
