# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 18:08:45 by sehkang           #+#    #+#              #
#    Updated: 2021/07/14 22:32:05 by sehkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS = ${SRCS_SERVER:.c=.o}
OBJS2 = ${SRCS_CLIENT:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${NAME2}:	${OBJS2}
	${CC} ${CFLAGS} ${OBJS2} -o ${NAME2}

all: ${NAME} ${NAME2}

clean:
	${RM} ${OBJS}
	${RM} ${OBJS2}

fclean: clean
	${RM} ${NAME}
	${RM} ${NAME2}

re: fclean all

.PHONY : all clean fclean re
