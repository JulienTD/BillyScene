/*
** EPITECH PROJECT, 2018
** set_str_to
** File description:
** set_str_to
*/

#include "bs_prototypes.h"

char *bs_set_str_to(char *src, char *new_str)
{
    if (new_str == NULL) {
        if (src) {
            free(src);
        }
        return (NULL);
    }
    if (src != NULL)
        free(src);
    src = malloc((bs_strlen(new_str) + 1) * sizeof(char));
    if (src == NULL)
        return (NULL);
    src = bs_strcpy(new_str, src);
    return (src);
}
