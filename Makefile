NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c read_utils.c string_utils.c display_functions.c func_helpers1_display.c func_helpers2_display.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
