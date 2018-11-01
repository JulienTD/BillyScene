##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME			=	libbs_scene.a

SRC_BUTTONS		=	./src/button/button_add_to_scene.c \
				./src/button/button_create.c \
				./src/button/button_destroy.c \
				./src/button/button_hitbox.c \
				./src/button/button_render.c \
				./src/button/button_set_base_clicked_hover_texture.c \
				./src/button/button_set_base_texture.c \
				./src/button/button_set_clicked_texture.c \
				./src/button/button_set_hover_texture.c \
				./src/button/button_set_pos.c \
				./src/button/button_set_size.c \
				./src/button/button_set_sound_click.c \
				./src/button/button_set_sound_hover_in.c \
				./src/button/button_set_sound_hover_out.c

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

SRC_EVENTS_TEXTFIELDS	=	./src/events/textfield/event_textfield_text_entered.c

SRC_EVENTS		=	./src/events/event_dispatcher.c

SRC_FRAME		=	./src/frame/frame_create.c \
				./src/frame/frame_destroy.c

SRC_LIST		=	./src/list/list_create.c \
				./src/list/list_delete.c \
				./src/list/list_get_element.c \
				./src/list/list_length.c \
				./src/list/list_push.c

SRC_SCENES		=	./src/scene/scene_add_to_frame.c \
				./src/scene/scene_create.c \
				./src/scene/scene_get_by_id.c \
				./src/scene/scene_render_all_buttons.c \
				./src/scene/scene_render_all_labels.c \
				./src/scene/scene_render_all_sprites.c \
				./src/scene/scene_render_all_textfields.c \
				./src/scene/scene_render.c \
				./src/scene/scene_set_to.c

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
				./src/sprite/sprite_set_speed.c

SRC_SPRITES_ANIMATIONS	=	./src/sprite/animation/sprite_anim_add.c \
				./src/sprite/animation/sprite_anim_create.c \
				./src/sprite/animation/sprite_anim_get_active.c \
				./src/sprite/animation/sprite_anim_get_by_id.c \
				./src/sprite/animation/sprite_anim_get_default.c \
				./src/sprite/animation/sprite_anim_play.c \
				./src/sprite/animation/sprite_anim_render.c \
				./src/sprite/animation/sprite_anim_stop.c

SRC_LABEL		=	./src/label/label_create.c \
				./src/label/label_render.c \
				./src/label/label_add_to_scene.c \
				./src/label/label_set_pos.c \
				./src/label/label_set_str.c \
				./src/label/label_get_str.c

SRC_TEXTFIELD		=	./src/textfield/textfield_create.c \
				./src/textfield/textfield_render.c \
				./src/textfield/textfield_set_focus.c \
				./src/textfield/textfield_add_to_scene.c

OBJ			=	$(SRC_BUTTONS:.c=.o) $(SRC_EVENTS_BUTTONS:.c=.o)  \
				$(SRC_EVENTS_KEYS:.c=.o) $(SRC_EVENTS:.c=.o) \
				$(SRC_FRAME:.c=.o) $(SRC_LIST:.c=.o) \
				$(SRC_SCENES:.c=.o) $(SRC_UTILS:.c=.o) \
				$(SRC_SOUNDS:.c=.o) $(SRC_EVENTS_SCENES:.c=.o) \
				$(SRC_SPRITES:.c=.o) $(SRC_EVENTS_GENERAL:.c=.o) \
				$(SRC_SPRITES_ANIMATIONS:.c=.o) $(SRC_LABEL:.c=.o) \
				$(SRC_TEXTFIELD:.c=.o) $(SRC_EVENTS_TEXTFIELDS:.c=.o)

ALL_SRC			=	$(SRC_BUTTONS) $(SRC_EVENTS_BUTTONS) $(SRC_EVENTS_KEYS) \
				$(SRC_EVENTS) $(SRC_FRAME) $(SRC_LIST) $(SRC_SCENES) $(SRC_UTILS) \
				$(SRC_SOUNDS) $(SRC_EVENTS_SCENES) $(SRC_SPRITES) $(SRC_EVENTS_GENERAL) \
				$(SRC_LABEL) $(SRC_SPRITES_ANIMATIONS) $(SRC_TEXTFIELD) $(SRC_EVENTS_TEXTFIELDS)

FLAGS	=			-Wunused-parameter -Wall -W -Wextra -pedantic -I./include/ -lc_graph_prog

all:	$(NAME)

$(NAME):	$(ALL_SRC)
	gcc -c $(ALL_SRC) -I./include/ $(FLAGS) -g3
	ar -rc $(NAME) *.o

%.o:	%.c
	gcc -o $@ -c $< $(FLAGS)

re:	fclean all clean

SRC_TEST	=	./tests/test_list_push.c \
			./tests/test_bs_set_str_to.c

tests_run: $(ALL_SRC)
	make re
	gcc $(ALL_SRC) $(SRC_TEST) -o all_tests -lcriterion --coverage $(FLAGS) -I../include/
	./all_tests

clean:
	rm -f $(OBJ) *.o *~ \#*\# *.gcda *.gcno

fclean:	clean
	rm -f $(NAME)

SRC_EXAMPLE	=	./example/main.c

EXAMPLE_OBJ	=	$(SRC_EXAMPLE:.c=.o)

ex: re example clean

example:  $(EXAMPLE_OBJ)
	gcc $(EXAMPLE_OBJ) -o ex -L. -lbs_scene -I./include/ -lc_graph_prog -g3
