/*
** EPITECH PROJECT, 2018
** Function: bs_scene_create
** File description:
** Tests the function bs_scene_create
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_scene_create, basic) {
	bs_scene_t *scene = bs_scene_create("test");

	cr_assert_not_null(scene);
	cr_assert_str_eq(scene->id_scene, "test");
	cr_assert_null(scene->button_list);
	cr_assert_null(scene->sprite_list);
	cr_assert_null(scene->label_list);
	cr_assert_null(scene->pbuffer_list);
	cr_assert_null(scene->textfield_list);
	cr_assert(scene->current_tick == 0);
	cr_assert_null(scene->event_key_pressed);
	cr_assert_null(scene->event_mouse_pressed);
	cr_assert_null(scene->event_mouse_released);
	cr_assert_null(scene->event_mouse_moved);
	cr_assert_null(scene->event_mouse_wheel_scrolled);
	cr_assert_null(scene->event_text_entered);
	cr_assert_null(scene->event_tick);
	cr_assert_null(scene->event_init);
	cr_assert_null(scene->event_init_post);
}
