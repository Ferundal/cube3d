# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:46:25 by cjettie           #+#    #+#              #
#    Updated: 2020/11/16 17:00:42 by cjettie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER			= cub3d.h

HEADERDIR		=	-I ./headers/ \
					-I ./libft/ \
					-I ./minilibx_mms_20200219/

LIBFT			=	-L./libft -lft

LIBMLX			=	-L./minilibx_mms_20200219 -lmlx

LIBMLXOG		=	-L./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

SRCS			= src/cub3d.c \
				src/cub3d_errors.c \
				src/cub3d_parcer.c \
				src/cub3d_atoi.c \
				src/flag_utils.c \
				src/get_next_line.c \
				src/get_next_line_utils.c \
				src/cub3d_read_par.c \
				src/cub3d_read_par_res.c \
				src/cub3d_read_par_texture.c \
				src/cub3d_read_par_color.c \
				src/cub3d_read_map.c \
				src/cub3d_read_map_check.c \
				src/cub3d_map_utils.c \
				src/cub3d_map_check_flow.c \
				src/cub3d_draw.c \
				src/cub3d_mlx_image_utils.c \
				src/cub3d_raycast.c \
				src/cub3d_hooks.c \
				src/cub3d_raycast_move.c \
				src/cub3d_raycast_rotate.c \
				src/cub3d_raycast_utils.c \
				src/cube3d_math.c \
				src/cub3d_screen.c

TURNIN			= ${HEADER} ${SRCS}

NORMO			= ${TURNIN}

OBJS			= ${SRCS:.c=.o}

NAME			= cub3d

CC				= cc
RM				= rm -f
AR				= ar -r

CFLAGS			= -Wall -Wextra -Werror -g

NORM			= norminette

.c.o:
				${CC} ${CFLAGS} ${HEADERDIR} -c $< -o ${<:.c=.o}

ifndef COMPILE_BONUS
${NAME}:		${OBJS}
				${MAKE} -C libft
				${MAKE} -C minilibx_mms_20200219
				cp ./minilibx_mms_20200219/libmlx.dylib libmlx.dylib
				${CC} -o ${NAME} ${OBJS} ${LIBFT} ${LIBMLX}
else
${NAME}:		${OBJS}
				${MAKE} -C libft
				${MAKE} -C minilibx_mms_20200219
				${CC} -o ${NAME} ${OBJS} ${LIBFT} ${LIBMLX}
endif

bonus:
				${MAKE} COMPILE_BONUS=1 all

all:			${NAME}

clean:
				${MAKE} -C libft clean
				${MAKE} -C minilibx_mms_20200219 clean
				${RM} ${OBJS} ${OBJS_B} libmlx.dylib

fclean:			${MAKE} clean
				${RM} ${NAME}

norm:		
				${NORM} ${NORMO}

re:				fclean ${NAME}

.PHONY:			all clean fclean re bonus
