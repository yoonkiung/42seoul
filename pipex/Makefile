# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiyoon <kiyoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 17:00:12 by kiyoon            #+#    #+#              #
#    Updated: 2022/03/28 17:00:17 by kiyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = pipex

LIBFT       = libft

LIBFT_LIB   = libft.a

SRCS        = ./main.c ./parsing_init.c ./check_path.c ./redirection.c ./fork_and_pipe.c  #수정필요

OBJS        = $(SRCS:.c=.o)

INCS        = .

RM          = rm -f

CC          = gcc

CFLAGS      = -Wall -Wextra -Werror -g3 -fsanitize=address #수정필요

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS) $(LIBFT_LIB)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
