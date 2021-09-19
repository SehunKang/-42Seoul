# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 20:36:25 by sehkang           #+#    #+#              #
#    Updated: 2021/09/19 10:58:41 by sehkang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract_ol
BONUS = fract_ol_bonus
CC = gcc -O3
FLAGS = -Wall -Werror -Wextra

SRC_NAME = main.c fractal_src.c events.c color.c arg_check.c
SRC_PATH = ./src
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

BONUS_SRC_NAME = main.c fractal_src.c event_key.c event_mouse.c color.c arg_check.c
BONUS_SRC_PATH = ./bonus
BONUS_SRC = $(addprefix $(BONUS_SRC_PATH)/, $(BONUS_SRC_NAME))

BONUS_OBJ_NAME = $(BONUS_SRC_NAME:.c=.o)
BONUS_OBJ_PATH = ./obj_bonus
BONUS_OBJ = $(addprefix $(BONUS_OBJ_PATH)/, $(BONUS_OBJ_NAME))

INC = -I ./include -I $(LIB_PATH)/include -I $(MLX_PATH)
LIB_PATH = ./libft
LIB = -L $(LIB_PATH) -lft
MLX_PATH = ./mlx

FRAMEWORK = -framework Metal -framework MetalKit

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(INC) -c $< -o $@

$(BONUS_OBJ_PATH)/%.o : $(BONUS_SRC_PATH)/%.c
	@mkdir -p $(BONUS_OBJ_PATH)
	$(CC) $(INC) -c $< -o $@

all : $(NAME) $(BONUS)

bonus : $(BONUS)

$(NAME) : $(OBJ)
	@make -C $(MLX_PATH)
	@make -C $(LIB_PATH)
	$(CC) $(INC) $(LIB) -L $(MLX_PATH) -lmlx $(FRAMEWORK) -o $(NAME) $(SRC)
	@install_name_tool -change libmlx.dylib $(MLX_PATH)/libmlx.dylib $(NAME)

$(BONUS) : $(BONUS_OBJ)
	@make -C $(MLX_PATH)
	@make -C $(LIB_PATH)
	$(CC) $(INC) $(LIB) -L $(MLX_PATH) -lmlx $(FRAMEWORK) -o $(BONUS) $(BONUS_SRC)
	@install_name_tool -change libmlx.dylib $(MLX_PATH)/libmlx.dylib $(BONUS)

clean :
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIB_PATH)
	rm -rf $(OBJ_PATH)
	rm -rf $(BONUS_OBJ_PATH)

fclean : clean
	@make fclean -C $(LIB_PATH)
	rm -rf $(NAME)
	rm -rf $(BONUS)

re : fclean all

.PHONY : all, clean, fclean, re, bonus
