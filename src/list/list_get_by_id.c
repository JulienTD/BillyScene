/*
** BillyScene, 2018
** list_get_by_id
** File description:
** bs_list_get_by_id
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Get an item of the list by id
 * 
 * @param head
 * @param id
 */
bs_list_t *bs_list_get_by_id(bs_list_t **head, int id)
{
    bs_list_t *curr = NULL;

    if (head == NULL || *head == NULL)
        return (NULL);
    curr = *head;
    while (curr) {
        if (curr->id == id) {
            return curr;
        }
        curr = curr->next;
    }
    return (NULL);
}