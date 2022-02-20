# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/09 22:04:27 by sehkang           #+#    #+#              #
#    Updated: 2021/08/03 15:26:21 by sehkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = GCC
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

SRC_NAME =ft_isascii.c\
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

SRC_PATH = ./srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))

INC = ./includes

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

${NAME}:	${OBJ}
	@${AR} $@ $^

all: ${NAME}

clean:
	@${RM} ${OBJ} ${OBJ_PATH}

fclean: clean
	@${RM} ${NAME}

re:	fclean all

.PHONY : bonus all clean fclean re 
