################################################################################
#                                     CONFIG                                   #
################################################################################

MAKEFLAGS += 	--silent
NAME	= 	cub3D
FLAGS		= 	-g3 -Wall -Werror -Wextra -o3
FL_MLX		=	-ldl -lmlx -Lmlx -lm -lXext -lX11 -Imlx mlx/libmlx.a

COMPILER	= 	cc

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

OBJS	= ${SRCS:.c=.o}
OBJS	:= $(addprefix objs/,${OBJS})
DEP		= $(OBJS:.o=.d)

################################################################################
#                                 Makefile rules                               #
################################################################################
all:		compilation setup ${NAME}


define	progress_bar
	echo  -n "\r \e[1;32m 5%   [■■■ . . . . . . . . . . ]"
	sleep 0.2
	echo  -n "\r \e[1;32m 10%  [■■■■■■. . . . . . . . . ]"
	sleep 0.2
	echo  -n "\r \e[1;32m 28%  [■■■■■■■■■■. . . . . . . ]"
	sleep 0.2
	echo -n "\r \e[1;32m 42%  [■■■■■■■■■■■■. . . . . . ]"
	sleep 0.1
	echo -n "\r \e[1;32m 55%  [■■■■■■■■■■■■■■■■. . . . ]"
	sleep 0.1
	echo -n "\r \e[1;32m 69%  [■■■■■■■■■■■■■■■■■■■ . . ]"
	sleep 0.2
	echo -n "\r \e[1;32m 100% [■■■■■■■■■■■■■■■■■■■■■■■■]"
	echo " "
endef

compilation:
	echo "        "
	echo "\e[1;37m            ███████╗███████╗████████╗██╗  ██╗"
	sleep 0.1
	echo "\e[1;37m            ██╔════╝██╔════╝╚══██╔══╝██║  ██║"
	sleep 0.1
	echo "\e[1;37m            ███████╗█████╗     ██║   ███████║"
	sleep 0.1
	echo "\e[1;37m            ╚════██║██╔══╝     ██║   ██╔══██║"
	sleep 0.1
	echo "\e[1;37m            ███████║███████╗   ██║   ██║  ██║"
	sleep 0.1
	echo "\e[1;37m            ╚══════╝╚══════╝   ╚═╝   ╚═╝  ╚═╝"
	sleep 0.1
	echo "        "
	echo "\e[1;37m            ██╗     ███████╗███╗   ██╗███╗   ██╗██╗   ██╗"
	sleep 0.1
	echo "\e[1;37m            ██║     ██╔════╝████╗  ██║████╗  ██║╚██╗ ██╔╝"
	sleep 0.1
	echo "\e[1;37m            ██║     █████╗  ██╔██╗ ██║██╔██╗ ██║ ╚████╔╝"
	sleep 0.1
	echo "\e[1;37m            ██║     ██╔══╝  ██║╚██╗██║██║╚██╗██║  ╚██╔╝"
	sleep 0.1
	echo "\e[1;37m            ███████╗███████╗██║ ╚████║██║ ╚████║   ██║"
	echo "        "
	sleep 0.3
	echo "\033[1;33m ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗ check files ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗"
	echo "        "
	@$(call progress_bar)
	echo "        "
	echo "\033[1;33m ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗ compilation ‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗‗"
	echo "        "
	sleep 1

$(NAME):	${OBJS} ${INCLUDES}
			@make -C ./mlx
			${COMPILER} ${FLAGS} -I includes ${OBJS} -o $(NAME) $(FL_MLX)

setup:
	@$(call progress_bar)

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
