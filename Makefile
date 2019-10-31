NAME = xzx

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = main.c brain.c debug.c random.c \
       brain_helpers.c think.c

OBJS = $(SRCS:.c=.o)

HEADER = header.h

all:	$(HEADER) $(NAME)
	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean
	make all
