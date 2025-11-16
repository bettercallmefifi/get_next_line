NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c \
	get_next_line_utils.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

  
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re