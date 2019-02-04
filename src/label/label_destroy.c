/*
** BillyScene, 2018
** label_destroy
** File description:
** bs_label_destroy
*/

#include "bs_components.h"
#include "bs_prototypes.h"
#include <stdbool.h>

/**
 * @brief Destroys label
 * 
 * @param label
 */
void bs_label_destroy(bs_label_t *label)
{
    if (label == NULL)
        return;
    if (label->id_label)
        free(label->id_label);
    if (label->font)
        sfFont_destroy(label->font);
    if (label->text)
        sfText_destroy(label->text);
    if (label->rs)
        free(label->rs);
    free(label);
}