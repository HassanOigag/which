CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)
NAME = _which

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)