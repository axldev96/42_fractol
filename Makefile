# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 18:50:31 by acaceres          #+#    #+#              #
#    Updated: 2023/10/21 03:24:33 by acaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/hooks/hook_handler.c \
	$(SRC_DIR)/hooks/key_hooks.c \
	$(SRC_DIR)/mlx_utils/ft_mlx_pixel_put.c \
	$(SRC_DIR)/fractals/draw_fractal.c \
	$(SRC_DIR)/utils/interpolate.c \
	$(SRC_DIR)/utils/sum_complex.c \
	$(SRC_DIR)/utils/square_complex.c \
	$(SRC_DIR)/utils/ft_strtod.c \
	$(SRC_DIR)/utils/ft_strncmp.c \
	$(SRC_DIR)/utils/select_complex_numbers.c \
	$(SRC_DIR)/utils/check_fractals.c \
	$(SRC_DIR)/utils/ft_isdigit.c \
	$(SRC_DIR)/utils/ft_strlen.c \
	$(SRC_DIR)/inits/init_scales.c \
	$(SRC_DIR)/inits/init_fractol.c \
	$(SRC_DIR)/inits/init_mlx.c	\
	$(SRC_DIR)/inits/init_base_values.c

OBJ = $(SRC:.c=.o)
MAIN_TARGET = all

UNAME := $(shell uname)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCL = -Iinclude
MLX_MAC_INCLUDE = -Imlx
MLX_MAC_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
MLX_LINUX_INCLUDE = -I/usr/include -Imlx_linux -O3
MLX_LINUX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(RM) = rm

# linux compilation:
ifeq ($(UNAME), Linux)
%.o: %.c
	$(CC) $(CFLAGS) $(INCL) $(MLX_LINUX_INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCL) $(OBJ) $(MLX_LINUX_FLAGS) -o $(NAME)
endif

# macos commpilation:
ifeq ($(UNAME), Darwin)
%.o: %.c
	$(CC) $(CFLAGS) $(INCL) $(MLX_MAC_INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCL) $(OBJ) $(MLX_MAC_FLAGS) -o $(NAME)
endif

all: $(NAME)

re: fclean
	$(MAKE) $(MAIN_TARGET)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
