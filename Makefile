# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/09 22:04:27 by sehkang           #+#    #+#              #
#    Updated: 2021/05/12 10:52:12 by sehkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = GCC
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS =ft_isascii.c\
	ft_memcmp.c\
	ft_putnbr_fd.c\
	ft_strlcpy.c\
	ft_strtrim.c\
	ft_atoi.c\
	ft_isdigit.c\
	ft_memcpy.c\
	ft_putstr_fd.c\
	ft_strlen.c\
	ft_substr.c\
	ft_bzero.c\
	ft_split.c\
	ft_isprint.c\
	ft_memmove.c\
	ft_strchr.c\
	ft_strmapi.c\
	ft_tolower.c\
	ft_calloc.c\
	ft_itoa.c\
	ft_memset.c\
	ft_strdup.c\
	ft_strncmp.c\
	ft_toupper.c\
	ft_isalnum.c\
	ft_memccpy.c\
	ft_putchar_fd.c\
	ft_strjoin.c\
	ft_strnstr.c\
	ft_isalpha.c\
	ft_memchr.c\
	ft_putendl_fd.c\
	ft_strlcat.c\
	ft_strrchr.c\

SRCS_B = ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${AR} $@ $^

bonus: ${OBJS_B}
	${AR} ${NAME} $^

all: ${NAME}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY : bonus all clean fclean re 
