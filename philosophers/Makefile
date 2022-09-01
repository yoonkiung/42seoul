# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kiyoon <kiyoon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 16:35:53 by kiyoon            #+#    #+#              #
#    Updated: 2022/07/14 16:35:54 by kiyoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = philo

SRCS        = ./main.c ./scheduling.c ./utils.c ./utils2.c ./tracking.c

OBJS        = $(SRCS:.c=.o)

RM          = rm -f

CC          = gcc

CFLAGS      = -Wall -Wextra -Werror -pthread #-g3 -fsanitize=thread

.c.o : $(SRC)
	$(CC) $(CFLAGS) -c $^

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
