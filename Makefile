	# Library Name #
NAME	= 	cub3D

	# Compilator #
COMPILER	= 	cc

	# Variables #
SRCS		= 	main.c \
				check/check_celling_floor.c \
				check/check_file.c \
				check/check_map.c \
				check/check_order_in_file.c \
				check/check_kid.c \
				check/check_rgb.c \
				check/check_walls.c \
				errors/print_error.c \
				free/free_failed_parsing.c \
				free/free.c \
				free/free_img.c \
				free/free_structs.c \
				free/free_utils.c \
				game/camera.c \
				game/introduction.c \
				game/keys.c \
				game/move.c \
				images/assign_img.c \
				init/init_game.c \
				init/init_img.c \
				init/init_map.c \
				init/init_structs.c \
				init/init_structs2.c \
				map/draw_map.c \
				map/draw_lines.c \
				map/verifications.c \
				maths/find_size.c \
				parsing/collect_celling_floor.c \
				parsing/collect_file.c \
				parsing/collect_map.c \
				parsing/collect_map_lines.c \
				parsing/collect_walls.c \
				raycasting/init.c \
				raycasting/draw.c \
				raycasting/raycasting.c \
				raycasting/set_view.c \
				raycasting/textures.c \
				utils/recognize_elements.c \
				utils/utils_digits.c \
				utils/utils_dtab.c \
				utils/utils_gnl.c \
				utils/utils_is.c \
				utils/utils_is2.c \
				utils/utils_mem.c \
				utils/utils_split.c \
				utils/utils_split_charset.c \
				utils/utils_str.c \
				utils/utils_str2.c \
				utils/utils_write.c \

INCLUDES 	= 	includes/cub3D.h

	# Colors Foreground #
DEFAULT		=	\033[0;39m
BLACK		=	\033[0;30m
RED			=	\033[0;31m
RED_B		=	\033[1;31m
L_RED		=	\033[0;91m
GREEN		=	\033[0;32m
GREEN_B		=	\033[1;32m
L_GREEN		=	\033[0;92m
YELLOW		=	\033[0;33m
L_YELLOW	=	\033[0;93m
BLUE		=   \033[0;34m
BLUE_B		=	\033[1;34m
L_BLUE		=   \033[0;94m
PINK		=	\033[0;35m
L_PINK		=	\033[0;95m
SKY			=   \033[0;36m
SKY_B		=	\033[1;36m
L_CYAN		=   \033[0;96m
GREY		=	\033[0;37m
D_GREY		=	\033[0;90m
WHITE		=	\033[0;97m
RESET		=	\e[0m

	# Colors Background #
NOIR		=	\033[0;40m
ROUGE		=	\033[0;41m
L_ROUGE		=	\033[0;101m
VERT		=	\033[0;42m
L_VERT		=	\033[0;102m
JAUNE		=	\033[0;43m
L_JAUNE		=	\033[0;103m
BLEU		=	\033[0;44m
L_BLEU		=	\033[0;104m
ROSE		=	\033[0;45m
L_ROSE		=	\033[0;105m
CYAN		=	\033[0;46m
L_CYAN		=	\033[0;106m
GRIS		=	\033[0;100m
BLANC		=	\033[0;107m

	# Objects #
OBJS	= ${SRCS:.c=.o}
OBJS	:= $(addprefix objs/,${OBJS})
DEP		= $(OBJS:.o=.d)

	# Flags #

FLAGS		= 	-g3 -Wall -Werror -Wextra -o3
FL_MLX		=	-ldl -lmlx -Lmlx -lm -lXext -lX11 -Imlx mlx/libmlx.a

	# Rules #
all:		${NAME}

$(NAME):	${OBJS} ${INCLUDES}
			@make -C ./mlx
			${COMPILER} ${FLAGS} -I includes ${OBJS} -o $(NAME) $(FL_MLX)


-include $(DEP)

objs/%.o:		srcs/%.c
					@mkdir -p $(dir $@)
					@${COMPILER} -MMD ${FLAGS} -I includes -o $@ -c $<
# -lmlx -lbass

clean:
			@make -C ./mlx clean
			rm -f ${OBJS}

fclean:
			@make -C ./mlx clean
			rm -f ${OBJS}
			rm -f ${NAME}
			rm -rf objs


re:			fclean all


.PHONY: 	all norme clean fclean re
