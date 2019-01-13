/*
** EPITECH PROJECT, 2017
** scene_manager
** File description:
** scene_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

static bool inits_scene_events(bs_scene_t *scene)
{
    scene->event_key_pressed = NULL;
    scene->event_mouse_pressed = NULL;
    scene->event_mouse_released = NULL;
    scene->event_mouse_moved = NULL;
    scene->event_mouse_wheel_scrolled = NULL;
    scene->event_text_entered = NULL;
    scene->event_tick = NULL;
    scene->event_init = NULL;
    scene->event_init_post = NULL;
    return (true);
}

/**
 * @brief Creates scene
 * 
 * @param id 
 * @return bs_scene_t* 
 */
bs_scene_t *bs_scene_create(char *id)
{
    bs_scene_t *scene = malloc(sizeof(bs_scene_t));

    if (scene == NULL)
        return (NULL);
    scene->id_scene = NULL;
    scene->id_scene = bs_set_str_to(scene->id_scene, id);
    scene->components_list = NULL;
    scene->current_tick = 0;
    inits_scene_events(scene);
    return (scene);
}