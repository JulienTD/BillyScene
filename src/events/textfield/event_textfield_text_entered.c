/*
** EPITECH PROJECT, 2018
** key_pressed_event
** File description:
** key_pressed_event
*/

#include "bs_events.h"
#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

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
 * @brief 
 * 
 * @param textfield 
 * @param evt 
 * @return true 
 * @return false 
 */
bool bs_textfield_text_entered_manager(bs_textfield_t *textfield, \
sfTextEvent evt)
{
	char c;

	if (textfield == NULL || textfield->label == NULL)
		return (false);
	if (textfield->is_focus == false)
		return (false);
	if (!(evt.unicode >= 0 && evt.unicode <= 127)) {
		return (false);
	}
	c = sanitize_char(evt.unicode);
	if (evt.unicode == 8) {
		apply_backspace(textfield);
	} else {
		fill_textfield(textfield, c);	
	}
	return (true);
}