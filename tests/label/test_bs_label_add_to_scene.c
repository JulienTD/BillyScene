/*
** EPITECH PROJECT, 2018
** Function: bs_label_add_to_scene
** File description:
** Tests the function bs_label_add_to_scene
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_label_add_to_scene, basic) {
	bs_label_t *label = bs_label_create("test", \
	"./tests/res/font.ttf", "", 10);
	bs_scene_t *scene = bs_scene_create("test");
	bool status = false;

	cr_assert_not_null(label);
	cr_assert_not_null(scene);
	status = bs_label_add_to_scene(scene, label);
	cr_assert(status == true);
}

Test(bs_label_add_to_scene, button_null) {
	bs_label_t *label = NULL;
	bs_scene_t *scene = bs_scene_create("test");
	bool status = true;

	cr_assert_not_null(scene);
	status = bs_label_add_to_scene(scene, label);
	cr_assert(status == false);
}

Test(bs_label_add_to_scene, scene_null) {
	bs_label_t *label = bs_label_create("test", \
	"./tests/res/font.ttf", "", 10);
	bs_scene_t *scene = NULL;
	bool status = true;

	cr_assert_not_null(label);
	status = bs_label_add_to_scene(scene, label);
	cr_assert(status == false);
}
