CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c
OBJ = $(SRC:.c=.o)
NAME = get_next_line

all: $(NAME)

$(NAME): $(OBJ)
    $(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all
