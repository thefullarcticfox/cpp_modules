NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
INCLUDEDIR = ./
CC = clang++
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDEDIR) -std=c++98
EXECFLAGS = $(CFLAGS)

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(EXECFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
