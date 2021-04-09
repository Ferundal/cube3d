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

HEADER=				${wildcard ./headers/*.h}

HEADERDIR=			-I ./headers/ \
					-I ./libft/ \
					-I ./minilibx_mms_20200219/

LIBFT=				-L./libft -lft

LIBFTNAME=			./libft/libft.a

LIBMLX=				-L./minilibx_mms_20200219 -lmlx

LIBMLXNAME=			./minilibx_mms_20200219/libmlx.dylib

LIBMLXNEWDEST=		./libmlx.dylib

SRCS=				src/cub3d.c \
					src/cub3d_errors.c \
					src/cub3d_parcer.c \
					src/cub3d_atoi.c \
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
					src/cub3d_mlx_ray_line.c \
					src/cub3d_mlx_sprite_line.c \
					src/cub3d_raycast.c \
					src/cub3d_hooks.c \
					src/cub3d_raycast_move.c \
					src/cub3d_raycast_rotate.c \
					src/cub3d_raycast_utils.c \
					src/cub3d_sprite.c \
					src/cube3d_math.c \
					src/cub3d_screen.c

TURNIN=				${HEADER} ${SRCS}

NORMO=				${TURNIN}

OBJS=				${SRCS:.c=.o} ${HEADER}

NAME=				cub3D

CC=					cc
RM=					rm -f
AR=					ar -r

CFLAGS=				-Wall -Wextra -Werror -g

NORM=				norminette

all:				libmlxmake ${LIBMLXNEWDEST} libftmake ${NAME}

.c.o:
					${CC} ${CFLAGS} ${HEADERDIR} -c $< -o ${<:.c=.o}

ifndef COMPILE_BONUS
${NAME}:			${OBJS} ${LIBFTNAME} ${LIBMLXNAME}
					${CC} -o ${NAME} ${OBJS} ${LIBFT} ${LIBMLX}
else
${NAME}:			${OBJS}
					${CC} -o ${NAME} ${OBJS} ${LIBFT} ${LIBMLX}
endif

bonus:
					${MAKE} COMPILE_BONUS=1 all

libmlxmake:
					${MAKE} -C minilibx_mms_20200219

${LIBMLXNEWDEST}:	${LIBMLXNAME}
					cp ./minilibx_mms_20200219/libmlx.dylib ./libmlx.dylib

libftmake:
					${MAKE} -C libft

clean:
					${MAKE} -C libft clean
					${MAKE} -C minilibx_mms_20200219 clean
					${RM} ${OBJS} ${OBJS_B} libmlx.dylib

fclean:
					${MAKE} -C libft fclean
					${MAKE} -C minilibx_mms_20200219 clean
					${RM} ${OBJS} ${OBJS_B} libmlx.dylib
					${RM} ${NAME}

norm:		
					${NORM} ${NORMO}

re:					fclean all

.PHONY:				all clean fclean re bonus libmlxmake libftmake
