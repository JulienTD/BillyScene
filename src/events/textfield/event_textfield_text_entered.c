/*
** BillyScene, 2018
** event_textfield_text_entered
** File description:
** bs_textfield_text_entered_manager
*/

#include <stdbool.h>
#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"

static bool execute_text_entered(bs_textfield_t *textfield, 
sfTextEvent event, bs_frame_t *frame, bs_scene_t *scene)
{
    bs_event_textfield_text_entered_t result;

    if (textfield == NULL || textfield->text_entered_event == NULL) {
        return (true);
    }
    result.event = event;
    result.frame = frame;
    result.textfield = textfield;
    result.scene = scene;
    return (textfield->text_entered_event(result));
}


static bool apply_backspace(bs_textfield_t *textfield)
{
    bs_label_t *label = textfield->label;
    char *ancient_str = bs_label_get_str(label);
    int size = bs_strlen(ancient_str);
    char *new_str = malloc(size * sizeof(char));
    int i = 0;

    if (new_str == NULL) {
        return (false);
    }
    if (size - 1 < 0) {
        bs_label_set_str(label, NULL);
        return (true);
    }
    for (i = 0; i < size; i++) {
        new_str[i] = ancient_str[i];
    }
    new_str[size - 1] = '\0';
    bs_label_set_str(label, new_str);
    return (true);
}

static bool fill_textfield(bs_textfield_t *textfield, char c)
{
    bs_label_t *label = textfield->label;
    char *ancient_str = bs_label_get_str(label);
    int size = bs_strlen(ancient_str);
    char *new_str = malloc((size + 2) * sizeof(char));
    int i = 0;

    if (new_str == NULL)
        return (false);
    for (i = 0; ancient_str[i] != '\0'; i++)
        new_str[i] = ancient_str[i];
    new_str[i++] = c;
    new_str[i] = '\0';
    bs_label_set_str(label, new_str);
    free(ancient_str);
    return (true);
}

static char sanitize_char(sfUint32 code)
{
    if (code == 13) {
        return '\n';
    }
    return (char)code;
}

/**
 * @brief Handles when text is entered.
 * 
 * @param textfield
 * @param evt
 * @return true
 * @return false
 */
bool bs_textfield_text_entered_manager(bs_textfield_t *textfield, \
sfTextEvent evt, bs_frame_t *frame, bs_scene_t *scene)
{
    char c;
    char *curr_str = NULL;

    if (textfield == NULL || textfield->label == NULL)
        return (false);
    if (textfield->is_focus == false || evt.unicode > 127)
        return (false);
    if (execute_text_entered(textfield, evt, frame, scene) == false)
        return (true);
    c = sanitize_char(evt.unicode);
    if (evt.unicode == 8) {
        apply_backspace(textfield);
        return (true);
    }
    curr_str = bs_label_get_str(textfield->label);
    if (textfield->max_length < 0 || \
    bs_strlen(curr_str) + 1 <= textfield->max_length)
        fill_textfield(textfield, c);
    free(curr_str);
    return (true);
}