# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 18:41:19 by sehkang           #+#    #+#              #
#    Updated: 2021/08/18 18:41:24 by sehkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 
CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_NAME = arg_utils.c list_utils.c other_utils.c swap_push_utils.c push_utils.c rotate_utils.c r_rotate_utils.c main.c shuffle_utils.c quick_sort.c
SRC_PATH = ./srcs
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INC = -I ./includes -I $(LIB_PATH)/includes
LIB = ./libft/libft.a
LIB_PATH = ./libft

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(LIB_PATH)
	$(CC) $(FLAGS) $(OBJ) $(INC) -L $(LIB_PATH) -lft -o $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean :
	@make clean -C $(LIB_PATH)
	rm -rf $(OBJ_PATH)

fclean : clean
	@make fclean -C $(LIB_PATH)
	rm -rf $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re
