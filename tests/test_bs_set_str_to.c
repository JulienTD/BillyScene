/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** test_list_push
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_set_str_to, wrong_input) {
	char *str = NULL;

	str = bs_set_str_to(str, "Je suis le nouveau str");
	cr_assert_str_eq(str, "Je suis le nouveau str");
}