/*
** EPITECH PROJECT, 2017
** event_manager
** File description:
** event_manager
*/

#include "bs_components.h"
#include "bs_prototypes.h"

static void bs_dispatch_scene_events(sfEvent event, bs_frame_t *frame, \
bs_scene_t *scene)
{
	if (event.type == sfEvtTextEntered)
		bs_scene_text_entered_manager(event.text, frame, scene);
	if (event.type == sfEvtKeyPressed)
		bs_scene_key_pressed_manager(event.key, frame, scene);
	if (event.type == sfEvtMouseButtonPressed)
		bs_scene_mouse_pressed_manager(event.mouseButton, frame, \
		scene);
	if (event.type == sfEvtMouseButtonReleased)
		bs_scene_mouse_released_manager(event.mouseButton, frame, \
		scene);
	if (event.type == sfEvtMouseMoved)
		bs_scene_mouse_moved_manager(event.mouseMove, frame, scene);
	if (event.type == sfEvtMouseWheelScrolled)
		bs_scene_mouse_wheel_scrolled_manager(event.mouseWheelScroll,\
		 frame, scene);
}

/**
 * @brief Dispatches events to the corresponding events manager
 * 
 * @param event 
 * @param frame 
 */
void bs_event_dispatcher(sfEvent event, bs_frame_t *frame)
{
	bs_scene_t *s = NULL;

	if (frame == NULL)
		return;
	s = bs_scene_get_by_id(frame, frame->current_scene);
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(frame->window);
	if (event.type == sfEvtMouseButtonPressed)
		bs_button_mouse_pressed_manager(event.mouseButton, frame, s);
	if (event.type == sfEvtMouseButtonReleased)
		bs_button_mouse_released_manager(event.mouseButton, frame, s);
	if (event.type == sfEvtMouseMoved)
		bs_button_mouse_move_manager(event.mouseMove, frame, s);
	if (event.type == sfEvtKeyPressed)
		bs_general_key_pressed_manager(event.key, frame, s);
	if (s == NULL)
		return;
	bs_dispatch_scene_events(event, frame, s);
}
