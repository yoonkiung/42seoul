NAME = megaphone

FLAG = -Wall -Wextra -Werror -std=c++98

CC = c++

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

$(NAME) : $(OBJS)
	$(CC) $(FLAG) -o $(NAME) $(OBJS)

all : $(NAME)

clean : 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all bonus clean clean re