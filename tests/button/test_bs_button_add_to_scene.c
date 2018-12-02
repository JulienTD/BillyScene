/*
** EPITECH PROJECT, 2018
** Function: bs_button_add_to_scene
** File description:
** Tests the function bs_button_add_to_scene
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_button_add_to_scene, basic) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bs_scene_t *scene = bs_scene_create("test");
	bool status = false;

	cr_assert_not_null(button);
	cr_assert_not_null(scene);
	status = bs_button_add_to_scene(scene, button);
	cr_assert(status == true);
}

Test(bs_button_add_to_scene, button_null) {
	bs_button_t *button = NULL;
	bs_scene_t *scene = bs_scene_create("test");
	bool status = true;

	cr_assert_not_null(scene);
	status = bs_button_add_to_scene(scene, button);
	cr_assert(status == false);
}

Test(bs_button_add_to_scene, scene_null) {
	bs_button_t *button = bs_button_create("test", 100, 100);
	bs_scene_t *scene = NULL;
	bool status = true;

	cr_assert_not_null(button);
	status = bs_button_add_to_scene(scene, button);
	cr_assert(status == false);
}