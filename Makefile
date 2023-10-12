# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaceres <acaceres@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/24 18:50:31 by acaceres          #+#    #+#              #
#    Updated: 2023/10/11 18:37:07 by acaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC_DIR = src
SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/hooks/hook_close.c \
	$(SRC_DIR)/mlx_utils/ft_mlx_pixel_put.c \
	$(SRC_DIR)/fractals/mandelbrot.c \
	$(SRC_DIR)/utils/interpolate.c \
	$(SRC_DIR)/utils/sum_complex.c \
	$(SRC_DIR)/utils/square_complex.c \
	$(SRC_DIR)/utils/scales.c

OBJ = $(SRC:.c=.o)
MAIN_TARGET = all

CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(RM) = rm

# linux compilation:
%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# macos commpilation:
#%.o: %.c
#	$(CC) -Imlx -c $< -o $@
#
#$(NAME): $(OBJ)
#	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

re: fclean
	$(MAKE) $(MAIN_TARGET)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)