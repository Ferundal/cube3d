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

SRCS			= cub3d.c \
				src/cub3d_errors.c \
				src/cub3d_parcer.c \
				src/cub3d_read_par.c \
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
				${CC} ${CFLAGS} -I ${HEADERDIR} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				${CC} -o ${NAME} -I ${HEADERDIR} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJS_B}

fclean:			clean
				${RM} ${NAME}

norm:		
				${NORM} ${NORMO}

re:				fclean ${NAME}

.PHONY:			all clean fclean re bonus
