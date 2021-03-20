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
				src/cub3d_draw.c \
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
				${CC} -o ${NAME} ${OBJS} ${LIBFT}
else
${NAME}:		${OBJS}
				${MAKE} -C libft
				${MAKE} -C minilibx_mms_20200219
				${CC} -o ${NAME} ${OBJS} ${LIBFT}
endif

bonus:
				${MAKE} COMPILE_BONUS=1 all

all:			${NAME}

clean:
				${MAKE} -C libft clean
				${MAKE} -C minilibx_mms_20200219 clean
				${RM} ${OBJS} ${OBJS_B}

fclean:
				${MAKE} -C libft fclean
				${MAKE} -C minilibx_mms_20200219 clean
				${RM} ${OBJS} ${OBJS_B}
				${RM} ${NAME}

norm:		
				${NORM} ${NORMO}

re:				fclean ${NAME}

.PHONY:			all clean fclean re bonus
