#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drenkas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/21 16:03:10 by drenkas           #+#    #+#              #
#    Updated: 2016/12/21 16:03:18 by drenkas          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= libft.a

NOC=\033[0m
OKC=\033[32m
ERC=\033[31m
WAC=\033[33m
BLU=\033[34m

CC = gcc
CFLAGS	+= -Wall -Werror -Wextra

SRC_PATH = ./

SRC_NAME += ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_abs.c\
ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_is_whitespace.c ft_pow.c ft_countw.c ft_sqrt.c ft_rot42.c ft_strndup.c \
ft_error.c get_next_line.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC_PATH = ./
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo -n =

$(NAME): $(OBJ)
	@echo
	@ar -rc $(NAME) $?
	@ranlib $(NAME)
	@echo "$(BLU)"
	@cat logo
	@echo "$(OKC)LIBFT:\t\tLIBFT ready$(NOC)"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)LIBFT:\t\tRemoving OBJ path: ./libft/obj/$(NOC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(WAC)LIBFT:\t\tRemoving Libft.a$(NOC)"

re: fclean all

