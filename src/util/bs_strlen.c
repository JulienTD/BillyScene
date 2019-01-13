/*
** EPITECH PROJECT, 2018
** bs_strlen
** File description:
** bs_strlen
*/

#include "bs_components.h"
#include "bs_prototypes.h"

int bs_strlen(char *str)
{
    int length = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    return (length);
}
