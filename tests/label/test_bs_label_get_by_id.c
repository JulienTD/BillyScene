/*
** EPITECH PROJECT, 2018
** Function: bs_label_get_by_id
** File description:
** Tests the function bs_label_get_by_id
*/

#include <criterion/criterion.h>
#include "bs_components.h"
#include "bs_prototypes.h"

Test(bs_label_get_by_id, basic) {
	bs_label_t *label1 = bs_label_create("test", \
	"./tests/res/font.ttf", "", 10);
	bs_label_t *label2 = bs_label_create("aa", \
	"./tests/res/font.ttf", "", 10);
	bs_scene_t *scene = bs_scene_create("test");
	bs_label_t *tmp_label = NULL;

	cr_assert_not_null(label1);
	cr_assert_not_null(label2);
	cr_assert_not_null(scene);
	bs_label_add_to_scene(scene, label1);
	bs_label_add_to_scene(scene, label2);
	tmp_label = bs_label_get_by_id(scene, "aa");
	cr_assert_not_null(tmp_label);
	cr_assert_not_null(tmp_label->id_label);
	cr_assert_str_eq("aa", tmp_label->id_label);
	bs_scene_destroy(scene);
}

Test(bs_label_get_by_id, scene_null) {
	bs_label_t *tmp_label = NULL;

	tmp_label = bs_label_get_by_id(NULL, "aa");
	cr_assert_null(tmp_label);
}

Test(bs_label_get_by_id, not_existing) {
	bs_label_t *label1 = bs_label_create("test", \
	"./tests/res/font.ttf", "", 10);
	bs_label_t *label2 = bs_label_create("aa", \
	"./tests/res/font.ttf", "", 10);
	bs_scene_t *scene = bs_scene_create("test");
	bs_label_t *tmp_label = NULL;

	cr_assert_not_null(label1);
	cr_assert_not_null(label2);
	cr_assert_not_null(scene);
	bs_label_add_to_scene(scene, label1);
	bs_label_add_to_scene(scene, label2);
	tmp_label = bs_label_get_by_id(scene, "mylabel");
	cr_assert_null(tmp_label);
	bs_scene_destroy(scene);
}

Test(bs_label_get_by_id, null_id) {
	bs_label_t *label1 = bs_label_create("test", \
	"./tests/res/font.ttf", "", 10);
	bs_label_t *label2 = bs_label_create("aa", \
	"./tests/res/font.ttf", "", 10);
	bs_scene_t *scene = bs_scene_create("test");
	bs_label_t *tmp_label = NULL;

	cr_assert_not_null(label1);
	cr_assert_not_null(label2);
	cr_assert_not_null(scene);
	bs_label_add_to_scene(scene, label1);
	bs_label_add_to_scene(scene, label2);
	tmp_label = bs_label_get_by_id(scene, NULL);
	cr_assert_null(tmp_label);
	bs_scene_destroy(scene);
}
