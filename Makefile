# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaceres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 11:01:16 by acaceres          #+#    #+#              #
#    Updated: 2023/10/02 01:48:45 by acaceres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c
OBJ = $(SRC:.c=.o)

CC = gcc
RM = rm -rf

%.o: %.c
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

re: fclean all

clean:
	$(RM) main.o

fclean: clean
	$(RM) $(NAME)

.PHONY: clean fclean all
