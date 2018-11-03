/*
** EPITECH PROJECT, 2018
** texts_manager
** File description:
** texts_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include "stdbool.h"

/**
 * @brief Destroys label
 * 
 * @param label 
 * @return true 
 * @return false 
 */
bool bs_label_destroy(bs_label_t *label)
{ 
	if (label == NULL)
		return (true);
	if (label->id_label)
		free(label->id_label);
	if (label->font)
		sfFont_destroy(label->font);
	if (label->text)
		sfText_destroy(label->text);
	free(label);
	return (true);
}