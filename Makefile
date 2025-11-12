# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: puzzlesanalytik <puzzlesanalytik@studen    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 15:45:08 by puzzlesanal       #+#    #+#              #
#    Updated: 2025/11/12 15:53:20 by puzzlesanal      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: monday <chat@openai.com>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 12:00:00 by monday            #+#    #+#              #
#    Updated: 2025/11/12 12:00:00 by monday           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

# Directories
SRC_DIR		:= src
OBJ_DIR		:= obj
BIN_DIR		:= bin
INC_DIR		:= includes
LIBS_DIR	:= includes

# Libs
LIBFT_DIR	:= $(LIBS_DIR)/libft
MLX42_DIR	:= $(LIBS_DIR)/MLX42

LIBFT		:= $(LIBFT_DIR)/libft.a
MLX42		:= $(MLX42_DIR)/build/libmlx42.a

# Compilation
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -MMD -MP \
			   -I$(LIBFT_DIR) \
			   -I$(MLX42_DIR)/include \
			   -I$(INC_DIR)
LDFLAGS		:= -L$(LIBFT_DIR) -lft \
			   -L$(MLX42_DIR)/build -lmlx42 \
			   -lglfw -lm -framework Cocoa -framework OpenGL -framework IOKit

# Files
SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEP_FILES	:= $(OBJ_FILES:.o=.d)

# Debug
DEBUG_NAME	:= $(NAME)_debug
DEBUG_DIR	:= $(OBJ_DIR)/debug
DEBUG_OBJS	:= $(patsubst $(SRC_DIR)/%.c,$(DEBUG_DIR)/%.o,$(SRC_FILES))
DEBUG_DEPS	:= $(DEBUG_OBJS:.o=.d)
DEBUG_FLAGS	:= $(CFLAGS) -g -fsanitize=address,undefined

# Default target
all: $(LIBFT) $(MLX42) $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(OBJ_FILES)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Debug target
debug: $(LIBFT) $(MLX42) $(BIN_DIR)/$(DEBUG_NAME)

$(BIN_DIR)/$(DEBUG_NAME): $(DEBUG_OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ $^ $(LDFLAGS) $(DEBUG_FLAGS)

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(DEBUG_DIR)
	$(CC) $(DEBUG_FLAGS) -c $< -o $@

# Dependencies
-include $(DEP_FILES)
-include $(DEBUG_DEPS)

# Lib rules
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build

# Cleaning
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(BIN_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(MLX42_DIR)/build

re: fclean all

.PHONY: all clean fclean re debug
