/*
** EPITECH PROJECT, 2018
** label_set_pos
** File description:
** Sets the position of the label
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

static bool set_default_values(bs_textfield_t *textfield)
{
	textfield->enabled = true;
	textfield->is_focus = false;
	textfield->max_length = -1;
	textfield->pos.x = 0;
	textfield->pos.y = 0;
	return (true);
}

/**
 * @brief Creates textfield structure
 * 
 * @param label 
 * @param pos_x 
 * @param pos_y 
 * @return true 
 * @return false 
 */
bs_textfield_t *bs_textfield_create(char *id, char *font_path, \
float width, float height)
{
	bs_textfield_t *textfield = malloc(sizeof(bs_textfield_t));
	sfVector2f size = {.x = width, .y = height};

	if (textfield == NULL)
		return (false);
	textfield->id_textfield = NULL;
	textfield->id_textfield = bs_set_str_to(textfield->id_textfield, id);
	textfield->rect = sfRectangleShape_create();
	sfRectangleShape_setSize(textfield->rect, size);
	set_default_values(textfield);
	textfield->texture = NULL;
	textfield->label = bs_label_create("", font_path, "", 12);
	textfield->focus_event = NULL;
	textfield->unfocus_event = NULL;
	textfield->text_entered_event = NULL;
	return (textfield);
}