/*
** BillyScene, 2018
** bs_set_str_to
** File description:
** bs_set_str_to
*/

#include "bs_prototypes.h"

/**
 * @brief Updates string content
 * 
 * @param src
 * @param new_str
 */
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
