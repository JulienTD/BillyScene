/*
** EPITECH PROJECT, 2018
** is_char_alpha_numeric
** File description:
** is_har_alphanumeric.
*/

#include "my_rpg.h"

int is_char_alphanumeric(char c)
{
	if (((c >= '0' && c <= '9') \
	|| (c >= 'a' && c <= 'z') || \
	(c >= 'A' && c <= 'Z') || \
	c == '_'))
		return (1);
	return (0);
}
