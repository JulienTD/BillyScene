/*
** EPITECH PROJECT, 2018
** Function: bs_button_get_by_id
** File description:
** Tests the function bs_button_get_by_id
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_button_get_by_id, basic) {
	bs_button_t *button1 = bs_button_create("test", 100, 100);
	bs_button_t *button2 = bs_button_create("aa", 100, 100);
	bs_scene_t *scene = bs_scene_create("test");
	bs_button_t *tmp_button = NULL;

	cr_assert_not_null(button1);
	cr_assert_not_null(button2);
	cr_assert_not_null(scene);
	bs_button_add_to_scene(scene, button1);
	bs_button_add_to_scene(scene, button2);
	tmp_button = bs_button_get_by_id(scene, "aa");
	cr_assert_not_null(tmp_button);
	cr_assert_not_null(tmp_button->id_button);
	cr_assert_str_eq("aa", tmp_button->id_button);
	bs_scene_destroy(scene);
}

Test(bs_button_get_by_id, scene_null) {
	bs_button_t *tmp_button = NULL;

	tmp_button = bs_button_get_by_id(NULL, "aa");
	cr_assert_null(tmp_button);
}

Test(bs_button_get_by_id, not_existing) {
	bs_button_t *button1 = bs_button_create("test", 100, 100);
	bs_button_t *button2 = bs_button_create("aa", 100, 100);
	bs_scene_t *scene = bs_scene_create("test");
	bs_button_t *tmp_button = NULL;

	cr_assert_not_null(button1);
	cr_assert_not_null(button2);
	cr_assert_not_null(scene);
	bs_button_add_to_scene(scene, button1);
	bs_button_add_to_scene(scene, button2);
	tmp_button = bs_button_get_by_id(scene, "mybutton");
	cr_assert_null(tmp_button);
	bs_scene_destroy(scene);
}

Test(bs_button_get_by_id, null_id) {
	bs_button_t *button1 = bs_button_create("test", 100, 100);
	bs_button_t *button2 = bs_button_create("aa", 100, 100);
	bs_scene_t *scene = bs_scene_create("test");
	bs_button_t *tmp_button = NULL;

	cr_assert_not_null(button1);
	cr_assert_not_null(button2);
	cr_assert_not_null(scene);
	bs_button_add_to_scene(scene, button1);
	bs_button_add_to_scene(scene, button2);
	tmp_button = bs_button_get_by_id(scene, NULL);
	cr_assert_null(tmp_button);
	bs_scene_destroy(scene);
}
