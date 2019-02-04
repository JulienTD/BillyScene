/*
** BillyScene, 2018
** list_destroy
** File description:
** bs_list_destroy
*/

#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Destroys a list with a custom function to destroy the data
 * 
 * @param head
 * @param destroy
 * @return true
 * @return false
 */
void bs_list_destroy(bs_list_t **head, void (*destroy)(bs_list_t *list))
{
    bs_list_t *curr = NULL;
    bs_list_t *tmp = NULL;

    if (head == NULL || *head == NULL)
        return;
    curr = *head;
    while (curr) {
        if (destroy != NULL) {
            destroy(curr);
            curr->data = NULL;
        }
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    *head = NULL;
}
