# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:46:25 by cjettie           #+#    #+#              #
#    Updated: 2021/01/21 17:00:10 by cjettie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER			= ft_printf.h src/utils.h

HEADER_B		=

SRC_DIS			= src

CODE			= src/flag_utils.c \
				  src/put_type_pointer.c \
				  src/ft_printf.c src/put_type_sign.c \
				  src/output_utils.c src/put_type_str.c \
				  src/parser.c src/put_type_uns.c \
				  src/put_nbr_all_signed_int.c src/put_type_utils.c \
				  src/put_nbr_all_unsigned_int.c src/read_precision.c \
				  src/read_size.c src/put_type_char.c \
				  src/read_width.c src/type_switch.c src/put_type_hexad.c

CODE_B			= 

TURNINHEADER	= ${HEADER} ${HEADER_B}

TURNINCODE		= ${CODE} ${CODE_B}

HEAD			= ${TURNINHEADER}

TURNIN			= ${TURNINHEADER} ${TURNINCODE}

SRCS			= ${CODE}

SRCS_B			= ${CODE_B}

NORMO			= ${TURNIN}

OBJS			= ${SRCS:.c=.o}

OBJS_B			= ${SRCS_B:.c=.o}

NAME			= libftprintf.a

CC				= cc
RM				= rm -f
AR				= ar -r

CFLAGS			= -Wall -Wextra -Werror -g

NORM			= norminette

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
ifndef COMPILE_BONUS
${NAME}:		${OBJS}
				${MAKE} -C libft
				mv libft/libft.a ./libftprintf.a
				${AR} ${NAME} ${OBJS}
else
${NAME}:		${OBJS}
				${MAKE} -C libft
				mv libft/libft.a ./libftprintf.a
				${AR} ${NAME} ${OBJS}
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

.PHONY:			all clean fclean re bonus norm
