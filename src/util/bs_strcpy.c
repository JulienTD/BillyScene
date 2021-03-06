/*
** BillyScene, 2018
** bs_strcpy
** File description:
** bs_strcpy
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Copies a string
 * 
 * @param src
 * @param dest
 */
char *bs_strcpy(char *src, char *dest)
{
    int i = 0;

    if (src == NULL || dest == NULL) {
        return (NULL);
    }
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
