/*
** BillyScene, 2017
** event_general_key_pressed
** File description:
** bs_general_key_pressed_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Key manager (default one)
 * 
 * @param event
 * @param frame
 */
void bs_general_key_pressed_manager(sfKeyEvent event, bs_frame_t *frame, \
bs_scene_t *scene)
{
    frame = frame;
    scene = scene;
    switch(event.code) {
    default:
        break;
    }
}
