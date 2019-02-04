/*
** EPITECH PROJECT, 2019
** BillyScene
** File description:
** bs_list
*/

#ifndef BS_LIST_H_
    #define BS_LIST_H_

#include "data_type.h"

typedef struct bs_list_s
{
    int id;
    void *data;
    bs_data_type_t data_type;
    struct bs_list_s *next;
} bs_list_t;

/*    PROTOTYPES    */
bs_list_t *bs_list_create(void *data, bs_data_type_t data_type);
bs_list_t *bs_list_delete(bs_list_t **head, int id);
bs_list_t *bs_list_get_by_id(bs_list_t **head, int id);
int bs_list_length(bs_list_t **head);
bs_list_t *bs_list_push(bs_list_t **head, void *data, \
bs_data_type_t data_type);
void bs_list_destroy(bs_list_t **head, void (*destroy)(bs_list_t *list));
bool bs_list_each(bs_list_t **head, \
bool (*func_each)(bs_list_t *element, va_list *args), ...);

#endif /* !BS_LIST_H_ */
