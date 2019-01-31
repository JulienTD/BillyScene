/*
** BillyScene, 2017
** scene_set_to
** File description:
** bs_scene_set_to
*/

#include "bs_components.h"
#include "bs_prototypes.h"

static bool execute_init_event(bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_scene_init_t result;

    if (scene == NULL || scene->event_init == NULL) {
        return (false);
    }
    result.scene = scene;
    result.frame = frame;
    scene->event_init(result);
    return (true);
}

static bool execute_init_post_event(bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_scene_init_t result;

    if (scene == NULL || scene->event_init_post == NULL) {
        return (false);
    }
    result.scene = scene;
    result.frame = frame;
    scene->event_init_post(result);
    return (true);
}

/**
 * @brief Change current scene to another
 * 
 * @param frame
 * @param id
 * @return true
 * @return false
 */
bool bs_scene_set_to(bs_frame_t *frame, char *id)
{
    bs_scene_t *current = NULL;

    if (frame == NULL || id == NULL)
        return (false);
    current = bs_scene_get_by_id(frame, id);
    if (current == NULL)
        return (false);
    execute_init_event(frame, current);
    frame->last_scene = frame->current_scene;
    frame->current_scene = bs_set_str_to(frame->current_scene, id);
    execute_init_post_event(frame, current);
    return (true);
}