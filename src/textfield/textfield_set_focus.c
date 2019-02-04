/*
** BillyScene, 2018
** textfield_set_focus
** File description:
** bs_textfield_set_focus
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Set Focus to textfield
 * 
 * @param textfield
 * @param is_focus
 */
bool bs_textfield_set_focus(bs_textfield_t *textfield, bool is_focus)
{
    bs_event_textfield_focus_t result;
    sfMouseButtonEvent event;

    if (textfield == NULL) {
        return (false);
    }
    if (textfield->focus_event) {
        event.x = 0;
        event.y = 0;
        event.type = sfEvtMouseButtonPressed;
        event.button = sfMouseLeft;
        result.textfield = textfield;
        result.frame = NULL;
        result.scene = NULL;
        result.event = event;
        textfield->focus_event(result);
    }
    textfield->is_focus = is_focus;
    return (true);
}
