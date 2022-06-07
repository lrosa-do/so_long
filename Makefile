BOLD="\e[1m"
RESET="\e[0m"
LIGHT_RED="\e[91m"
LIGHT_GREEN="\e[92m"
LIGHT_CYAN="\e[96m"

LIBFT_PATH		=	./libraries/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

NAME			=	so_long
CC				=	gcc
RM				=	rm -f

OSTYPE := $(shell uname)


INCLUDE_PATH = ./source/
HEADER		 =./source/so_long.h



SOURCES_FILES	=	so_long.c \
			draw_utils.c \
			func_extra.c \
			game_colider.c \
			game_colider2.c \
			game_core.c \
			game_core_ext.c \
			game_gems.c \
			game_load.c \
			game_load2.c \
			game_math.c \
			game_states.c \
			game_particles.c \
			game_particles_ex.c \
			game_emitter.c \
			game_objects.c \
			game_objects_add.c \
			game_objects_extra.c \
			game_player.c \
			game_player_ex.c \
			game_player_bullet.c \
			game_enemy.c \
			game_enemy2.c \
			game_enemy3.c \
			game_enemy_bullet.c \
			game_explosion.c \
			game_timer.c \
			image_list.c \
			game_ease.c \
			game_font.c \
			os_utils.c \
			libx_utils.c \
			libx_utils2.c \
			map_check.c \
			map_load.c \
			game_mac.c 






SOURCES_DIR		=	source
SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))
OBJECTS			= 	$(SOURCES:.c=.o)





MLXFLAGS		=	-lmlx -framework OpenGL -framework AppKit
CFLAGS			=	-g -Wall -Wextra -Werror -I$(INCLUDE_PATH)  -I$(LIBFT_PATH)


.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)



	
all:			$(NAME)




$(NAME):		$(LIBFT) $(OBJECTS) $(HEADER)
		$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $ $(MLXFLAGS) -o $(NAME)


$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)


clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS)


fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)


show:
	@printf "OS  		: $(OSTYPE)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "SRC		:\n	$(SOURCES)\n"
	@printf "OBJ		:\n	$(OBJECTS)\n"

re:				fclean all


.PHONY:			all show clean fclean re libft 


