# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/09 22:04:27 by sehkang           #+#    #+#              #
#    Updated: 2021/06/08 17:13:19 by sehkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = GCC
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_atoi.c ft_printf.c ft_isdigit.c ft_strlen.c ft_strnlen.c check_flag.c ft_itoa.c ft_strdup.c ft_memcpy.c ft_itoa_base_x.c ft_itoa_base_capx.c int_len.c int_len_base.c ft_itoa_base_add.c print_d.c print_p.c print_per.c print_s.c print_u.c print_x.c print_capx.c print_c.c check_print_neg.c

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${AR} $@ $^

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY : all clean fclean re 
