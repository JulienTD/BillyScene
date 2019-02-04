/*
** BillyScene, 2018
** event_scene_text_entered
** File description:
** bs_scene_text_entered_manager
*/

#include <stdbool.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

static bool fill_scene_textfields(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
    bs_list_t *curr = NULL;
    bs_textfield_t *textfield = NULL;

    if (scene == NULL || frame == NULL) {
        return false;
    }
    for (curr = scene->components_list; curr != NULL; curr = curr->next) {
        if (curr->data_type != BS_TEXTFIELD)
            continue;
        textfield = (bs_textfield_t *)curr->data;
        if (textfield->is_focus) {
            bs_textfield_text_entered_manager(textfield, evt, \
            frame, scene);
        }
    }
    return (true);
}

/**
 * @brief Handles Text Entered event in the scene.
 * 
 * @param evt
 * @param frame
 * @param scene
 */
bool bs_scene_text_entered_manager(sfTextEvent evt, bs_frame_t *frame, \
bs_scene_t *scene)
{
    bs_event_text_entered_t result;

    fill_scene_textfields(evt, frame, scene);
    if (scene == NULL || scene->event_text_entered == NULL) {
        return (false);
    }
    result.event = evt;
    result.frame = frame;
    result.scene = scene;
    scene->event_text_entered(result);
    return (true);
}