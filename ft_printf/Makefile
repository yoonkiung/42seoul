# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiyoon <kiyoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 17:05:45 by kiyoon            #+#    #+#              #
#    Updated: 2022/01/05 17:18:41 by kiyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

LIBFT       = libft

LIBFT_LIB   = libft.a

SRCS        = ./ft_printf.c ./util.c\
              ./print_c.c ./print_d.c ./print_p.c\
			  ./print_s.c ./print_u.c ./print_x.c\
			  ./print_xx.c

OBJS        = $(SRCS:.c=.o)

INCS        = .

RM          = rm -f

LIBC        = ar rc

CC          = gcc

CFLAGS      = -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
