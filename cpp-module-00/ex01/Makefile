NAME = phonebook
SRC = Contact.cpp Phonebook.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
INCLUDEDIR = ./
HEADERS = $(INCLUDEDIR)Phonebook.hpp $(INCLUDEDIR)Contact.hpp
CC = clang++
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDEDIR) -std=c++98
EXECFLAGS = $(CFLAGS)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(EXECFLAGS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
