NAME = phonebook

CC = c++

FLAG = -Wall -Wextra -Werror --std=c++98

SRCS = PhoneBook.cpp main.cpp Contact.cpp

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

.PHONY : all bonus clean clean re