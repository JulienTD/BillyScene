/*
** BillyScene, 2018
** scene_render
** File description:
** bs_scene_render
*/

#include "bs_components.h"
#include "bs_events.h"
#include "bs_prototypes.h"
#include <stdbool.h>

static bool execute_tick_event(bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_tick_t result;

    if (scene == NULL || scene->event_tick == NULL) {
        return false;
    }
    result.frame = frame;
    result.scene = scene;
    scene->event_tick(result);
    return true;
}

static bool render_component(bs_list_t *element, va_list *args)
{
    bs_frame_t *frame = (bs_frame_t *)va_arg(*args, void *);

    switch (element->data_type) {
        case BS_PIXEL_BUFFER:
            return bs_pbuffer_render(frame, (bs_pbuffer_t *)element->data);
        case BS_SPRITE:
            return bs_sprite_render(frame , (bs_sprite_t *)element->data);
        case BS_BUTTON:
            return bs_button_render(frame, (bs_button_t *)element->data);
        case BS_LABEL:
            return bs_label_render(frame, (bs_label_t *)element->data);
        case BS_TEXTFIELD:
            return bs_textfield_render(frame, (bs_textfield_t *)element->data);
        default:
            return (false);
    }
}

/**
 * @brief Renders scene
 * 
 * @param scene
 * @param frame
 * @return true
 * @return false
 */
bool bs_scene_render(bs_scene_t *scene, bs_frame_t *frame)
{
    if (scene == NULL || frame == NULL)
        return (false);
    if (scene->current_tick > frame->max_tick) {
        scene->current_tick = 0;
    }
    execute_tick_event(frame, scene);
    bs_list_each(&(scene->components_list), &render_component, frame);
    bs_sprite_render(frame, frame->cursor);
    scene->current_tick++;
    return (true);
}