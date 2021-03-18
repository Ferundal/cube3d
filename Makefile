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

HEADERDIR		= ./headers/

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
				src/cud3d_read_map.c \
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

LIBFT			=

NORM			= norminette

.c.o:
				${CC} ${CFLAGS} -I ${HEADERDIR} -c $< -o ${<:.c=.o}

ifndef COMPILE_BONUS
${NAME}:		${OBJS}
				${MAKE} -C libft
				${CC} -o ${NAME} -I ${HEADERDIR} ${OBJS}
else
${NAME}:		${OBJS}
				${MAKE} -C libft
				${CC} -o ${NAME} -I ${HEADERDIR} ${OBJS}
endif

bonus:
				${MAKE} COMPILE_BONUS=1 all

all:			${NAME}

clean:
				${MAKE} -C libft clean
				${RM} ${OBJS} ${OBJS_B}

fclean:
				${MAKE} -C libft fclean
				${RM} ${OBJS} ${OBJS_B}
				${RM} ${NAME}

norm:		
				${NORM} ${NORMO}

re:				fclean ${NAME}

.PHONY:			all clean fclean re bonus
