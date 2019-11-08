# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                                  #
#                                                   ||||||:||||::|||:|:|||:    #
#    By: fde-c <x@y.z>                              ::||:||:|::||::|:||::::    #
#                                                   |:|:|:::|::|::::::|||||    #
#    Created: 2019/11/06 00:16:52 by fde-c                                     #
#    Updated: 2019/11/08 12:03:15 by ||||||                                    #
#                                                                              #
# **************************************************************************** #

NAME = x

CC = gcc

FLAGS = -Wall -Werror -Wextra
FLAG2 = -v

SRCS =	main.c		\
		random.c	\
		debug.c		\
		brain.c		\
		genome.c	\
		helper.c

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

v:	$(OBJS)
	$(CC) $(FLAGS) $(FLAG2) $(OBJS) -o $(NAME)

