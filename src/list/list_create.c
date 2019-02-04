/*
** BillyScene, 2018
** list_create
** File description:
** bs_list_create
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Create List
 * 
 * @param data
 * @param data_type
 */
bs_list_t *bs_list_create(void *data, bs_data_type_t data_type)
{
    bs_list_t *element = malloc(sizeof(bs_list_t));

    if (element == NULL)
        return (NULL);
    element->id = 0;
    element->data = data;
    element->data_type = data_type;
    element->next = NULL;
    return element;
}
