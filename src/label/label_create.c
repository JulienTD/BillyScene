/*
** EPITECH PROJECT, 2018
** texts_manager
** File description:
** texts_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

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

bs_label_t *bs_label_create(char *id, char *font, char *text, int font_size)
{
	bs_label_t *label = NULL;
	sfVector2f pos = {.x = 0, .y = 0};

	if (id == NULL || font == NULL)
		return (NULL);
	label = malloc(sizeof(bs_label_t));
	if (label == NULL)
		return (NULL);
	if (init_label(label, font, id) == false)
		return (NULL);
	if (text != NULL)
		sfText_setString(label->text, text);
	sfText_setPosition(label->text, pos);
	sfText_setColor(label->text, sfBlack);
	sfText_setCharacterSize(label->text, font_size);
	return (label);
}
