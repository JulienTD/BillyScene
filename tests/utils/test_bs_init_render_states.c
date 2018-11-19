/*
** EPITECH PROJECT, 2018
** Function: bs_init_render_states
** File description:
** Tests the function bs_init_render_states
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_init_render_states, basic) {
	sfRenderStates *rs = bs_init_render_states();

	cr_assert_not_null(rs);
	cr_assert_null(rs->texture);
	cr_assert_null(rs->shader);
}
