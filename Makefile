# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 18:50:31 by acaceres          #+#    #+#              #
#    Updated: 2023/10/25 11:45:22 by acaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/hooks/hook_handler.c \
	$(SRC_DIR)/hooks/key_hooks.c \
	$(SRC_DIR)/hooks/mouse_hooks.c \
	$(SRC_DIR)/hooks/close_hook.c \
	$(SRC_DIR)/mlx_utils/ft_mlx_pixel_put.c \
	$(SRC_DIR)/fractals/draw_fractal.c \
	$(SRC_DIR)/fractals/check_fractals.c \
	$(SRC_DIR)/fractals/select_complex_numbers.c \
	$(SRC_DIR)/math_utils/interpolate.c \
	$(SRC_DIR)/math_utils/add_complex.c \
	$(SRC_DIR)/math_utils/subtract_complex.c \
	$(SRC_DIR)/math_utils/mult_complex.c \
	$(SRC_DIR)/math_utils/divide_complex.c \
	$(SRC_DIR)/math_utils/power_complex.c \
	$(SRC_DIR)/utils/ft_strtod.c \
	$(SRC_DIR)/utils/ft_strncmp.c \
	$(SRC_DIR)/utils/ft_isdigit.c \
	$(SRC_DIR)/utils/ft_strlen.c \
	$(SRC_DIR)/utils/print_help_usage.c \
	$(SRC_DIR)/inits/init_scales.c \
	$(SRC_DIR)/inits/init_fractol.c \
	$(SRC_DIR)/inits/init_mlx.c	\
	$(SRC_DIR)/inits/init_base_values.c

OBJ = $(SRC:.c=.o)
MAIN_TARGET = all

UNAME := $(shell uname)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

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
%.o: %.c $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCL) $(MLX_LINUX_INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(INCL) $(OBJ) $(FT_PRINTF) $(MLX_LINUX_FLAGS) -o $(NAME)
endif

# macos commpilation:
ifeq ($(UNAME), Darwin)
%.o: %.c $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCL) $(MLX_MAC_INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCL) $(OBJ) $(FT_PRINTF) $(MLX_MAC_FLAGS) -o $(NAME)
endif

$(FT_PRINTF):
	$(MAKE) -sC $(FT_PRINTF_DIR)

all: $(NAME)

re: fclean
	$(MAKE) $(MAIN_TARGET)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(FT_PRINTF_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)

.PHONY: all clean fclean re
