# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iporsenn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 14:46:44 by iporsenn          #+#    #+#              #
#    Updated: 2018/03/08 14:46:47 by iporsenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_PATH = src/
SRC_NAME =	aux.c			\
			check_map.c		\
			draw_segment.c	\
			draw_square.c	\
			init_struct.c	\
			key_hook.c		\
			main.c			\
			parsing.c		\
			print_parse.c

SRC =  $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDE_PATH = ./
INCLUDE_NAME =
INCLUDE = $(addprefix $(INCLUDE_PATH), $(INCLUDE_NAME))

OBJ_PATH = obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAME:.c=.o))

HEADER_PATH = minilibx_macos/
HEADER_NAME = libmlx.a
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
FLAGS_LIBX = -lmlx -framework OpenGL -framework AppKit -lpthread -D_REENTRANT

.PHONY: all, build, creadir, clean, fclean, rebuild, re

all: $(NAME)

$(NAME):	creadir $(OBJ)
	@make -C libft
	@gcc $(FLAGS) $(FLAGS_LIBX) $(SRC) ./libft/libft.a $(HEADER) -o $(NAME)
	@echo "\033[32mBuilding exe\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -o $@ -c $<

build : creadir
	@gcc $(FLAGS) $(FLAGS_LIBX) $(SRC) ./libft/libft.a $(HEADER) -o $(NAME)
	@echo "\033[32mBuilding exe\033[0m"

creadir:
	@mkdir -p $(OBJ_PATH)

clean:
	@make clean -C libft
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mCleaning .o\033[0m"

rebuild:
	@rm -rf $(OBJ_PATH)
	@echo "\033[31mCleaning .o\033[0m"
	@gcc $(FLAGS) $(FLAGS_LIBX) $(SRC) ./libft/libft.a $(HEADER) -o $(NAME)
	@echo "\033[32mBuilding exe\033[0m"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[31mCleaning all\033[0m"

re: fclean all
