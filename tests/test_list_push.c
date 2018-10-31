/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** test_list_push
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(list_push, wrong_input) {
	bs_list_t *head = NULL;

	bs_frame_t *frame = bs_create_frame();

	cr_assert(bs_list_push(&(head), frame) != NULL);
}

// Test(test_list_push, right_input) {
// 	char *cmd = "ls ; pwd > file ; cat file | grep home";

// 	cr_assert(check_wrong_raw_command(cmd) == false);
// }
