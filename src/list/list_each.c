/*
** BillyScene, 2017
** list_each
** File description:
** bs_list_each
*/

#include <stdarg.h>
#include "bs_components.h"
#include "bs_prototypes.h"

/**
 * @brief Calls a function for each element of list
 * 
 * @param head
 * @param func_each
 * @param ...
 */
bool bs_list_each(bs_list_t **head, \
bool (*func_each)(bs_list_t *element, va_list *args), ...)
{
    bs_list_t *curr = NULL;
    va_list args;
    va_list args_cpy;

    va_start(args, func_each);
    if (head == NULL || *head == NULL || func_each == NULL)
        return (false);
    curr = *head;
    while (curr) {
        if (func_each != NULL) {
            va_copy(args_cpy, args);
            func_each(curr, &args_cpy);
            va_end(args_cpy);
        }
        curr = curr->next;
    }
    va_end(args);
    return (true);
}
