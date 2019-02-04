/*
** BillyScene, 2018
** list_delete
** File description:
** bs_list_delete
*/

#include "bs_components.h"
#include "bs_prototypes.h"

static bs_list_t *delete_first_element(bs_list_t **head)
{
    bs_list_t *tmp = NULL;

    if (head == NULL || *head == NULL)
        return (NULL);
    tmp = *head;
    *head = (*head)->next;
    return (tmp);
}

/**
 * @brief Delete an item of the list
 * 
 * @param head
 * @param id
 */
bs_list_t *bs_list_delete(bs_list_t **head, int id)
{
    bs_list_t *curr = NULL;
    bs_list_t *before_curr = NULL;

    if (id == 0)
        return (delete_first_element(head));
    curr = bs_list_get_by_id(head, id);
    before_curr = bs_list_get_by_id(head, id - 1);
    if (curr == NULL || before_curr == NULL)
        return (NULL);
    before_curr->next = curr->next;
    return (curr);
}