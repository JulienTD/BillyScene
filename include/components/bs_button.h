/*
** EPITECH PROJECT, 2019
** BillyScene
** File description:
** bs_button
*/

#ifndef BS_BUTTON_H_
    #define BS_BUTTON_H_

#include <SFML/Graphics.h>
#include "bs_events.h"
#include "components/bs_sound.h"
#include "components/bs_frame.h"
#include "components/bs_scene.h"

/*    EVENTS    */
typedef struct bs_event_button_click_pressed_s
{
    sfMouseButtonEvent event;
    struct bs_frame_s *frame;
    struct bs_button_s *button;
    struct bs_scene_s *scene;
} bs_event_button_click_pressed_t;

typedef struct bs_event_button_click_released_s
{
    sfMouseButtonEvent event;
    struct bs_frame_s *frame;
    struct bs_button_s *button;
    struct bs_scene_s *scene;
} bs_event_button_click_released_t;

typedef struct bs_event_button_hover_s
{
    sfMouseMoveEvent event;
    struct bs_frame_s *frame;
    struct bs_button_s *button;
    struct bs_scene_s *scene;
} bs_event_button_hover_t;

typedef struct bs_event_button_hover_in_s
{
    sfMouseMoveEvent event;
    struct bs_frame_s *frame;
    struct bs_button_s *button;
    struct bs_scene_s *scene;
} bs_event_button_hover_in_t;

typedef struct bs_event_button_hover_out_s
{
    sfMouseMoveEvent event;
    struct bs_frame_s *frame;
    struct bs_button_s *button;
    struct bs_scene_s *scene;
} bs_event_button_hover_out_t;

/*    COMPONENT    */

typedef enum bs_button_status_e
{
    NORMAL,
    HOVERED,
    CLICKED
} bs_button_status_t;

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


/*    PROTOTYPES    */
bool bs_button_add_to_scene(bs_scene_t *scene, bs_button_t *button);
bs_button_t *bs_button_create(char *id, float width, float heigth);
void bs_button_destroy(bs_button_t *button);
bool bs_is_mouse_on_button(bs_button_t button, float clickX, float clickY);
bool bs_button_render(bs_frame_t *frame, bs_button_t *button);
bool bs_button_set_base_clicked_hover_texture(bs_button_t *button, \
char *path);
bool bs_button_set_texture_base(bs_button_t *button, char *path);
bool bs_button_set_texture_clicked(bs_button_t *button, char *path);
bool bs_button_set_texture_hover(bs_button_t *button, char *path);
bool bs_button_set_pos(bs_button_t *button, float pos_x, float pos_y);
bool bs_button_set_offset(bs_button_t *button, \
float offset_x, float offset_y);
bool bs_button_set_size(bs_button_t *button, float width, float height);
bool bs_button_set_sound_click(bs_button_t *button, char *path);
bool bs_button_set_sound_hover_in(bs_button_t *button, char *path);
bool bs_button_set_sound_hover_out(bs_button_t *button, char *path);
bs_button_t *bs_button_get_by_id(bs_scene_t *scene, char *id);

#endif /* !BS_BUTTON_H_ */
