##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

# CONFIG
NAME			=	libbs_scene.a

SRC_BUTTONS		=	./src/button/button_add_to_scene.c \
					./src/button/button_create.c \
					./src/button/button_destroy.c \
					./src/button/button_hitbox.c \
					./src/button/button_render.c \
					./src/button/button_set_base_clicked_hover_texture.c \
					./src/button/button_set_texture_base.c \
					./src/button/button_set_texture_clicked.c \
					./src/button/button_set_texture_hover.c \
					./src/button/button_set_pos.c \
					./src/button/button_set_size.c \
					./src/button/button_set_sound_click.c \
					./src/button/button_set_sound_hover_in.c \
					./src/button/button_set_sound_hover_out.c \
					./src/button/button_get_by_id.c \
					./src/button/button_set_offset.c

SRC_EVENTS_BUTTONS	=	./src/events/button/event_button_mouse_move.c \
						./src/events/button/event_button_mouse_pressed.c \
						./src/events/button/event_button_mouse_released.c

SRC_EVENTS_GENERAL	=	./src/events/general/event_general_key_pressed.c

SRC_EVENTS_SCENES	=	./src/events/scene/event_scene_key_pressed.c \
						./src/events/scene/event_scene_mouse_moved.c \
						./src/events/scene/event_scene_mouse_pressed.c \
						./src/events/scene/event_scene_mouse_released.c \
						./src/events/scene/event_scene_mouse_wheel_scrolled.c \
						./src/events/scene/event_scene_text_entered.c

SRC_EVENTS_TEXTFIELDS	=	./src/events/textfield/event_textfield_text_entered.c \
							./src/events/textfield/event_textfield_mouse_pressed.c

SRC_EVENTS		=	./src/events/event_dispatcher.c

SRC_FRAME		=	./src/frame/frame_create.c \
					./src/frame/frame_destroy.c \
					./src/frame/frame_set_cursor.c

SRC_LIST		=	./src/list/list_create.c \
					./src/list/list_delete.c \
					./src/list/list_get_by_id.c \
					./src/list/list_length.c \
					./src/list/list_push.c \
					./src/list/list_destroy.c \
					./src/list/list_each.c

SRC_SCENES		=	./src/scene/scene_add_to_frame.c \
					./src/scene/scene_create.c \
					./src/scene/scene_get_by_id.c \
					./src/scene/scene_render.c \
					./src/scene/scene_set_to.c \
					./src/scene/scene_destroy.c

SRC_UTILS		=	./src/util/bs_set_str_to.c \
					./src/util/bs_str_are_equals.c \
					./src/util/bs_strcpy.c \
					./src/util/bs_strlen.c \
					./src/util/bs_init_render_states.c

SRC_SOUNDS		=	./src/sound/sound_create.c \
					./src/sound/sound_destroy.c \
					./src/sound/sound_play.c \
					./src/sound/sound_set_new.c

SRC_SPRITES		=	./src/sprite/sprite_add_to_scene.c \
					./src/sprite/sprite_create.c \
					./src/sprite/sprite_get_by_id.c \
					./src/sprite/sprite_render.c \
					./src/sprite/sprite_set_pos.c \
					./src/sprite/sprite_set_scale.c \
					./src/sprite/sprite_set_size.c \
					./src/sprite/sprite_set_speed.c \
					./src/sprite/sprite_destroy.c \
					./src/sprite/sprite_set_offset.c

SRC_SPRITES_ANIMATIONS	=	./src/sprite/animation/sprite_anim_add.c \
							./src/sprite/animation/sprite_anim_create.c \
							./src/sprite/animation/sprite_anim_get_active.c \
							./src/sprite/animation/sprite_anim_get_by_id.c \
							./src/sprite/animation/sprite_anim_get_default.c \
							./src/sprite/animation/sprite_anim_play.c \
							./src/sprite/animation/sprite_anim_render.c \
							./src/sprite/animation/sprite_anim_stop.c \
							./src/sprite/animation/sprite_anim_destroy.c

SRC_LABEL		=	./src/label/label_create.c \
					./src/label/label_render.c \
					./src/label/label_add_to_scene.c \
					./src/label/label_set_pos.c \
					./src/label/label_set_str.c \
					./src/label/label_get_str.c \
					./src/label/label_destroy.c \
					./src/label/label_get_by_id.c \
					./src/label/label_set_color.c \
					./src/label/label_set_offset.c

SRC_TEXTFIELD		=	./src/textfield/textfield_create.c \
						./src/textfield/textfield_render.c \
						./src/textfield/textfield_set_focus.c \
						./src/textfield/textfield_add_to_scene.c \
						./src/textfield/textfield_destroy.c \
						./src/textfield/textfield_get_by_id.c \
						./src/textfield/textfield_hitbox.c \
						./src/textfield/textfield_set_max_length.c \
						./src/textfield/textfield_set_pos.c \
						./src/textfield/textfield_set_offset.c

SRC_PIXELBUFFER		=	./src/pixelbuffer/pbuffer_add_to_scene.c \
						./src/pixelbuffer/pbuffer_clear.c \
						./src/pixelbuffer/pbuffer_create.c \
						./src/pixelbuffer/pbuffer_render.c \
						./src/pixelbuffer/pbuffer_set_pixel.c \
						./src/pixelbuffer/pbuffer_set_pos.c \
						./src/pixelbuffer/pbuffer_destroy.c \
						./src/pixelbuffer/pbuffer_get_by_id.c \
						./src/pixelbuffer/pbuffer_set_offset.c

ALL_SRC			=	$(SRC_BUTTONS) $(SRC_EVENTS_BUTTONS) $(SRC_EVENTS_KEYS) \
				$(SRC_EVENTS) $(SRC_FRAME) $(SRC_LIST) $(SRC_SCENES) $(SRC_UTILS) \
				$(SRC_SOUNDS) $(SRC_EVENTS_SCENES) $(SRC_SPRITES) $(SRC_EVENTS_GENERAL) \
				$(SRC_LABEL) $(SRC_SPRITES_ANIMATIONS) $(SRC_TEXTFIELD) $(SRC_EVENTS_TEXTFIELDS) \
				$(SRC_PIXELBUFFER)

OBJ			=	$(SRC_BUTTONS:.c=.o) $(SRC_EVENTS_BUTTONS:.c=.o)  \
				$(SRC_EVENTS_KEYS:.c=.o) $(SRC_EVENTS:.c=.o) \
				$(SRC_FRAME:.c=.o) $(SRC_LIST:.c=.o) \
				$(SRC_SCENES:.c=.o) $(SRC_UTILS:.c=.o) \
				$(SRC_SOUNDS:.c=.o) $(SRC_EVENTS_SCENES:.c=.o) \
				$(SRC_SPRITES:.c=.o) $(SRC_EVENTS_GENERAL:.c=.o) \
				$(SRC_SPRITES_ANIMATIONS:.c=.o) $(SRC_LABEL:.c=.o) \
				$(SRC_TEXTFIELD:.c=.o) $(SRC_EVENTS_TEXTFIELDS:.c=.o) \
				$(SRC_PIXELBUFFER:.c=.o)

# -lc_graph_prog
FLAGS	=			-Wunused-parameter -Wall -W -Wextra -pedantic -I./include/ -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -O3

wc:
	wc $(ALL_SRC)

# Lib
all:	$(NAME)

$(NAME):	$(ALL_SRC)
	gcc -c $(ALL_SRC) -I./include/ $(FLAGS)
	ar -rc $(NAME) *.o

%.o:	%.c
	gcc -o $@ -c $< $(FLAGS)

re:	fclean all clean

# Tests
SRC_TEST	=	./tests/list/test_list_push.c \
			./tests/list/test_list_create.c \
			./tests/list/test_list_each.c \
			./tests/list/test_list_length.c \
			./tests/list/test_list_get_by_id.c \
			./tests/list/test_list_destroy.c \
			./tests/list/test_list_delete.c \
			./tests/utils/test_bs_set_str_to.c \
			./tests/utils/test_bs_strlen.c \
			./tests/utils/test_bs_strcpy.c \
			./tests/utils/test_bs_str_are_equals.c \
			./tests/utils/test_bs_init_render_states.c \
			./tests/frame/test_bs_frame_create.c \
			./tests/frame/test_bs_frame_set_cursor.c \
			./tests/scene/test_bs_scene_create.c \
			./tests/scene/test_bs_scene_get_by_id.c \
			./tests/scene/test_bs_scene_add_to_frame.c \
			./tests/scene/test_bs_scene_set_to.c \
			./tests/scene/test_bs_scene_render.c \
			./tests/button/test_bs_button_create.c \
			./tests/button/test_bs_button_add_to_scene.c \
			./tests/button/test_bs_button_get_by_id.c \
			./tests/button/test_bs_button_render.c \
			./tests/button/test_bs_button_hitbox.c \
			./tests/button/test_bs_button_set_pos.c \
			./tests/button/test_bs_button_set_size.c \
			./tests/button/test_bs_button_set_sound_click.c \
			./tests/button/test_bs_button_set_sound_hover_in.c \
			./tests/button/test_bs_button_set_sound_hover_out.c \
			./tests/button/test_bs_button_set_texture_base.c \
			./tests/button/test_bs_button_set_texture_clicked.c \
			./tests/button/test_bs_button_set_texture_hover.c \
			./tests/label/test_bs_label_create.c \
			./tests/label/test_bs_label_add_to_scene.c \
			./tests/label/test_bs_label_get_by_id.c \
			./tests/label/test_bs_label_get_str.c


tests_run: $(ALL_SRC)
	make re
	gcc $(ALL_SRC) $(SRC_TEST) -o all_tests -lcriterion --coverage $(FLAGS) -I../include/
	./all_tests

# Cleaning
clean:
	rm -f $(OBJ) *.o *~ \#*\# *.gcda *.gcno *.gcov

fclean:	clean
	rm -f $(NAME)

# Example
SRC_EXAMPLE	=	./example/main.c

EXAMPLE_OBJ	=	$(SRC_EXAMPLE:.c=.o)

ex: re example clean

example:  $(EXAMPLE_OBJ)
	gcc $(EXAMPLE_OBJ) -o ex -L. -lbs_scene -I./include/ -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -g3

exwin: $(EXAMPLE_OBJ)
	x86_64-w64-mingw32-gcc $(EXAMPLE_OBJ) -o ex.exe -L. -lbs_scene -I./include/ -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
