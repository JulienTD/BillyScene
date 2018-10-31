/*
** EPITECH PROJECT, 2018
** textfield
** File description:
** textfield
*/

#include "my_rpg.h"

textfield_t *create_textfield(sfVector2f position, sfVector2f size, \
char *font_path)
{
	textfield_t *textfield = malloc(sizeof(textfield_t));

	if (textfield == NULL)
		return (NULL);
	textfield->rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(textfield->rect, position);
	sfRectangleShape_setSize(textfield->rect, size);
	textfield->text_info = create_text(font_path, NULL, position, 50);
	textfield->is_focus = 1;
	textfield->max_lenght = 10;
	textfield->enabled = true;
	textfield->id_name = NULL;
	textfield->texture = NULL;
	return (textfield);
}

void apply_backspace(sfTextEvent event, scene_t *scene)
{
	list_t *head = scene->textfield_list;
	char const *text = NULL;
	char *tmp = NULL;

	while (head) {
		if (head->textfield->is_focus == 1 \
		&& head->textfield->enabled == true) {
			text = sfText_getString(head->textfield->text_info \
			->text);
			tmp = malloc((my_strlen(text) + 1) * sizeof(char));
			my_strcpy(tmp, text);
			tmp[my_strlen(text) - 1] = '\0';
			sfText_setString(head->textfield->text_info->text, \
			tmp);
		}
		head = head->next;
	}
}

static void fill_textfield2(sfTextEvent event, list_t *head)
{
	char const *text = sfText_getString(head->textfield->text_info->text);
	int max_size = head->textfield->max_lenght;
	char *tmp = NULL;

	if (head->textfield->is_focus == 1 && \
	my_strlen(text) < max_size && head->textfield->enabled) {
		tmp = malloc((my_strlen(text) + 1) * sizeof(char));
		my_strcpy(tmp, text);
		tmp = my_remalloc(tmp, 1, STR, 0);
		tmp[my_strlen(text)] = (char)(event.unicode);
		sfText_setString(head->textfield->text_info->text, tmp);
	}
}

void fill_textfield(sfTextEvent event, scene_t *scene)
{
	list_t *head = scene->textfield_list;

	if (event.unicode >= 128)
		return;
	if (event.unicode == 8 || event.unicode == 127) {
		apply_backspace(event, scene);
		return;
	} else if (!is_char_alphanumeric(event.unicode))
		return;
	while (head) {
		fill_textfield2(event, head);
		head = head->next;
	}
}

int render_textfield(frame_t *frame, textfield_t *textfield)
{
	sfRenderStates *states = NULL;

	if (frame == NULL || textfield == NULL || textfield->enabled == false)
		return (1);
	states = init_render_states();
	if (states == NULL)
		return (1);
	if (textfield->texture)
		sfRectangleShape_setTexture(textfield->rect, \
		textfield->texture, sfFalse);
	sfRenderWindow_drawRectangleShape(frame->window, textfield->rect, \
	states);
	render_text(frame, textfield->text_info);
	free(states);
	return (0);
}
