NAME = account

CC = c++

FLAG = -Wall -Wextra -Werror --std=c++98

SRCS = Account.cpp test.cpp

OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CC) $(FLAG) -c -o $@ $^

clean : 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean clean re