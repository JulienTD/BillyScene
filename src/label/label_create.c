/*
** BillyScene, 2018
** label_create
** File description:
** bs_label_create
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

static bool init_label(bs_label_t *label, char *font, char *id)
{
    label->font = sfFont_createFromFile(font);
    if (label->font == NULL)
        return (false);
    label->text = sfText_create();
    if (label->text == NULL)
        return (false);
    label->enabled = true;
    label->id_label = NULL;
    label->id_label = bs_set_str_to(label->id_label, id);
    if (label->id_label == NULL)
        return (false);
    label->rs = bs_init_render_states();
    if (label->rs == NULL)
        return (false);
    return (true);
}

/**
 * @brief Create a label struct
 * 
 * @param id
 * @param font
 * @param text
 * @param font_size
 */
bs_label_t *bs_label_create(char *id, char *font, char *text, int font_size)
{
    bs_label_t *label = NULL;

    if (id == NULL || font == NULL)
        return (NULL);
    label = malloc(sizeof(bs_label_t));
    if (label == NULL)
        return (NULL);
    if (init_label(label, font, id) == false)
        return (NULL);
    if (text != NULL)
        sfText_setString(label->text, text);
    bs_label_set_offset(label, 0, 0);
    bs_label_set_pos(label, 0, 0);
    bs_label_set_color(label, sfBlack);
    sfText_setCharacterSize(label->text, font_size);
    return (label);
}
