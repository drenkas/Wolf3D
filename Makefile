#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drenkas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/17 16:39:27 by drenkas           #+#    #+#              #
#    Updated: 2017/01/17 16:39:29 by drenkas          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all, $(NAME), clean, fclean, re

NAME = wolf3d

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -O3 -g
FLAG = -lmlx -L ./mlx/ -I ./mlx/ -framework OpenGL -framework AppKit -lpthread

SRC_PATH = ./
INC_PATH = ./
OBJ_PATH = ./obj/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = wolf.h

SRC_NAME = main.c hooks.c draw.c map.c ray_caster.c color.c textures.c \
plyushki.c validation.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft $(FLAG)
	@echo "$(OKC)Wolf3D:\t\tWolf3D ready$(NOC)"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo -n =

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)Wolf3D:\t\tRemoving OBJ path: ./obj/$(NOC)"

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
	@echo "$(WAC)Wolf3D:\t\tRemoving Wolf3D executable$(NOC)"

re: fclean all
