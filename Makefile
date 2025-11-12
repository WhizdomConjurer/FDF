# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: reriebsc <reriebsc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 12:00:00 by monday            #+#    #+#              #
#    Updated: 2025/11/12 20:44:33 by reriebsc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := fdf

SRC_DIR := src
INC_DIR := includes
LIBS_DIR := includes

LIBFT_DIR := $(LIBS_DIR)/libft
MLX42_DIR := $(LIBS_DIR)/MLX42

LIBFT := $(LIBFT_DIR)/libft.a
MLX42 := $(MLX42_DIR)/build/libmlx42.a

CC      := cc
CFLAGS  := -Wall -Wextra -Werror \
           -I$(INC_DIR) \
           -I$(LIBFT_DIR) \
           -I$(MLX42_DIR)/include
LDFLAGS := -L$(LIBFT_DIR) -lft \
           -L$(MLX42_DIR)/build -lmlx42 \
           -lglfw -lm

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:.c=.o)

all: $(LIBFT) $(MLX42) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX42_DIR)/build
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
