# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 20:36:25 by sehkang           #+#    #+#              #
#    Updated: 2021/08/30 14:32:51 by sehkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol
CC = gcc -O3
FLAGS = -Wall -Werror -Wextra

SRC_NAME = *.c
SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SR_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

INC = -I ./include -I $(LIB_PATH)/include -I $(MLX_PATH)
LIB_PATH = ./libft
LIB = -L $(LIB_PATH) -lft
MLX_PATH = ./mlx

FRAMEWORK = -framework Metal -framework MetalKit

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(INC) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(MLX_PATH)
	@make -C $(LIB_PATH)
	$(CC) $(INC) $(LIB) -L $(MLX_PATH) -lmlx $(FRAMEWORK) -o $(NAME) $(SRC)
	@install_name_tool -change libmlx.dylib $(MLX_PATH)/libmlx.dylib $(NAME)

clean :
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIB_PATH)
	rm -rf $(OBJ_PATH)

fclean : clean
	@make fclean -C $(LIB_PATH)
	rm -rf $(NAME)

re : fclean all

rr :
	rm -rf $(NAME)

.PHONY : all, clean, fclean, re
