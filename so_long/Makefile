# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 21:43:07 by kiyoon            #+#    #+#              #
#    Updated: 2022/07/11 21:43:07 by kiyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c image.c map.c move.c ft_printerr.c ft_putnbr_fd.c \
		get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
RM = /bin/rm -f
MLX			= -L./mlx -lmlx -framework OpenGL -framework AppKit
ARCH		= arch -x86_64

all: $(NAME)

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c $^

$(NAME): $(OBJ)
	$(ARCH) $(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
