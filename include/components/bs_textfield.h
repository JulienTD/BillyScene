/*
** EPITECH PROJECT, 2019
** BillyScene
** File description:
** bs_textfield
*/

#ifndef BS_TEXTFIELD_H_
    #define BS_TEXTFIELD_H_

#include <stdbool.h>
#include <SFML/Graphics.h>
#include "components/bs_label.h"
#include "components/bs_frame.h"
#include "bs_events.h"


/*    EVENTS    */
typedef struct bs_event_textfield_focus_s
{
    sfMouseButtonEvent event;
    struct bs_frame_s *frame;
    struct bs_textfield_s *textfield;
    struct bs_scene_s *scene;
} bs_event_textfield_focus_t;

typedef struct bs_event_textfield_unfocus_s
{
    sfMouseButtonEvent event;
    struct bs_frame_s *frame;
    struct bs_textfield_s *textfield;
    struct bs_scene_s *scene;
} bs_event_textfield_unfocus_t;

typedef struct bs_event_textfield_text_entered_s
{
    sfTextEvent event;
    struct bs_frame_s *frame;
    struct bs_textfield_s *textfield;
    struct bs_scene_s *scene;
} bs_event_textfield_text_entered_t;


/* COMPONENT */
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

/*    PROTOTYPES    */
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
bool bs_textfield_set_offset(bs_textfield_t *textfield, \
float offset_x, float offset_y);
bool bs_textfield_set_pos(bs_textfield_t *textfield, \
float pos_x, float pos_y);

#endif /* !BS_TEXTFIELD_H_ */
