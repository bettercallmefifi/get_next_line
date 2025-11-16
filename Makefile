NAME = get_next_line.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = get_next_line.c \
	get_next_line_utils.c
BSRC = get_next_line_bonus.c \
	get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS = $(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(BONUS)
	ar rcs $(NAME) $(BONUS)
  
clean:
	rm -f $(OBJS) $(BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus