/*
** EPITECH PROJECT, 2018
** texts_manager
** File description:
** texts_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

bs_label_t *bs_label_create(char *id, char *font, char *text, int font_size)
{
	bs_label_t *label = malloc(sizeof(bs_label_t));
	sfVector2f pos = {.x = 0, .y = 0};

	label->font = sfFont_createFromFile(font);
	label->text = sfText_create();
	label->enabled = true;
	label->id_label = NULL;
	label->id_label = bs_set_str_to(label->id_label, id);
	if (text != NULL)
		sfText_setString(label->text, text);
	sfText_setPosition(label->text, pos);
	sfText_setColor(label->text, sfBlack);
	sfText_setCharacterSize(label->text, font_size);
	return (label);
}