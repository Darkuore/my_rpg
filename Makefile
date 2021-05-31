##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	source/core/main.c									\
		source/core/my_rpg.c								\
		source/basics/init/param/create_window.c			\
		source/basics/init/param/clock_struct.c				\
		source/basics/init/param/setting.c					\
		source/basics/init/param/param.c					\
		source/basics/init/object/set_file.c				\
		source/basics/init/object/take_info.c				\
		source/basics/init/object/make_info.c				\
		source/basics/init/object/set.c						\
		source/basics/init/object/create_object.c			\
		source/basics/init/object/destroy_obj.c				\
		source/basics/init/object/all_obj.c					\
		source/basics/init/object/custom_struct.c			\
		source/basics/init/make_map.c						\
		source/basics/my_strncat.c							\
		source/basics/text.c								\
		source/basics/draw.c								\
		source/basics/itostr.c								\
		source/basics/gest_mouse.c							\
		source/menu/main_menu/main_menu.c					\
		source/menu/main_menu/menu_event.c					\
		source/menu/custom_map/custom_map.c					\
		source/menu/custom_map/custom_event.c				\
		source/menu/custom_map/custom_sprite.c				\
		source/menu/game_menu/game_menu.c					\
		source/menu/setting_menu/setting_menu.c				\
		source/menu/setting_menu/setting_event.c			\
		source/menu/how_to_play/how_to_play.c				\
		source/menu/how_to_play/how_to_play_event.c			\
		source/gameplay/gameplay.c							\
		source/gameplay/gameplay_event.c					\
		source/gameplay/movement/motion.c					\
		source/gameplay/view/init_view.c					\
		source/gameplay/movement/clock.c					\
		source/gameplay/quest/fight_interaction.c 	        \
		source/gameplay/quest/pnj_interaction.c				\
		source/mini_games/basics/analyse_events.c			\
		source/mini_games/basics/move_rect.c				\
		source/mini_games/basics/handle_text.c				\
		source/mini_games/basics/back_clock.c				\
		source/mini_games/fight/choose_fight.c				\
		source/mini_games/fight/clock_fight.c				\
		source/mini_games/fight/clock_marvin.c				\
		source/mini_games/fight/create_fight.c				\
		source/mini_games/fight/mini_fight.c				\
		source/mini_games/fight/move_char.c					\
		source/mini_games/fight/print_texts_fight.c			\
		source/mini_games/fight/win_lose.c					\
		source/mini_games/hunter/analyse_mission.c			\
		source/mini_games/hunter/clock.c					\
		source/mini_games/hunter/create_hunter.c			\
		source/mini_games/hunter/mini_hunter.c				\
		source/mini_games/hunter/move_sprites.c				\
		source/mini_games/hunter/print_texts_hunter.c		\
		source/mini_games/hunter/click_duck.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS =	-W -Wall -Wextra

CPPFLAGS =	-I./include/ -I./lib/include/

LDFLAGS =	-L./lib -lmy

LDLIBS =	-lmy -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

CC	=	gcc

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		make -sC lib/my/ libmy
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
		make -sC lib/my/ clean
		$(RM) $(OBJ)

fclean:		clean
		make -sC lib/my/ fclean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
