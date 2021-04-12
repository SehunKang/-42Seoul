# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 10:14:05 by sehkang           #+#    #+#              #
#    Updated: 2021/04/12 21:11:32 by sehkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OBJECTS = $(SRCS:.c=.o)
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c 
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
INC = includes
ARFLAGS = rcs
RM = rm -f
TARGET = libft.a

.c.o:
	${CC} ${CFLAGS} $< -o $(<:.c=.o) -I ${INC}

$(TARGET) : $(OBJECTS)
	$(AR) $(ARFLAGS) $@ $^

all : $(TARGET)

clean :
	$(RM) $(OBJECTS)

fclean : clean 
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re

