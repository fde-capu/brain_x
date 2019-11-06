# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                                  #
#                                                   ||||||:||||::|||:|:|||:    #
#    By: fde-c <x@y.z>                              ::||:||:|::||::|:||::::    #
#                                                   |:|:|:::|::|::::::|||||    #
#    Created: 2019/11/06 00:16:52 by fde-c                                     #
#    Updated: 2019/11/06 00:45:13 by fde-c                                     #
#                                                                              #
# **************************************************************************** #

NAME = x

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS =	main.c \
		random.c \
		debug.c

OBJS = $(SRCS:.c=.o)

HEADER = header.h

all:	$(HEADER) $(NAME)
	$(NAME)

$(NAME):	$(HEADER) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean
	make all
