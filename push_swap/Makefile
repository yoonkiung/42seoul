# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 11:12:01 by kiyoon            #+#    #+#              #
#    Updated: 2022/03/04 18:30:14 by kiyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

NAME_BONUS	= checker

LIBFT       = libft

LIBFT_LIB   = libft.a

SRCS        = ./main_push_swap.c ./deque1.c ./deque2.c ./input1.c ./input2.c ./instruction1.c ./instruction2.c ./sort1.c ./sort2.c ./sort3.c ./sort4.c ./sort5.c ./quicksort.c

SRCS_BONUS	= ./main_checker.c ./deque1.c ./deque2.c ./input1.c ./input2.c ./instruction1.c ./instruction2.c ./sort1.c ./sort2.c ./sort3.c ./sort4.c ./sort5.c ./quicksort.c ./instruct1_bonus.c ./instruct2_bonus.c ./instruction1_bonus.c ./instruction2_bonus.c 

OBJS        = $(SRCS:.c=.o)

OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

INCS        = .

RM          = rm -f

LIBC        = ar rc

CC          = gcc

CFLAGS      = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	mv $(LIBFT)/$(LIBFT_LIB) .
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB)

all : $(NAME)

bonus :	$(OBJS_BONUS)
	make all
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT_LIB)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT_LIB)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS) 
	$(RM) $(OBJS_BONUS)
	make clean -C $(LIBFT)

re : fclean all

.PHONY : all bonus clean clean re
