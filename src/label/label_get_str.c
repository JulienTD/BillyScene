/*
** EPITECH PROJECT, 2018
** label_set_pos
** File description:
** Sets the position of the label
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Gets label str
 * 
 * @param label 
 * @param str 
 * @return true 
 * @return false 
 */
char *bs_label_get_str(bs_label_t *label)
{
	const char *label_str = NULL;
	char *str = NULL;
	int length = 0;

	if (label == NULL) {
		return (NULL);
	}
	label_str = sfText_getString(label->text);
	if (label_str == NULL)
		return (NULL);
	for (length = 0; label_str[length] != '\0'; length++);
	str = malloc((length + 1) * sizeof(char));
	if (str == NULL) {
		return (NULL);
	}
	for (int i = 0; label_str[i] != '\0'; i++) {
		str[i] = label_str[i];
	}
	str[length] = '\0';
	return (str);
}
