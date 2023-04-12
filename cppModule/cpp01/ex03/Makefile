NAME = weapon

CC = c++

FLAG = -Wall -Wextra -Werror --std=c++98

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

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