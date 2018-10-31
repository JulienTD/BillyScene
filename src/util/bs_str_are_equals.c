/*
** EPITECH PROJECT, 2018
** bs_str_are_equals
** File description:
** bs_str_are_equals
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

bool bs_str_are_equals(char *str_1, char *str_2)
{
	int size_1 = bs_strlen(str_1);
	int size_2 = bs_strlen(str_2);

	if (str_1 == NULL || str_2 == NULL)
		return (false);
	if (size_1 != size_2)
		return (false);
	for (int i = 0; i < size_1; i++) {
		if (str_1[i] != str_2[i])
			return (false);
	}
	return (true);
}