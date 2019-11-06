# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                                  #
#                                                   ||||||:||||::|||:|:|||:    #
#    By: fde-c <x@y.z>                              ::||:||:|::||::|:||::::    #
#                                                   |:|:|:::|::|::::::|||||    #
#    Created: 2019/11/06 00:16:52 by fde-c                                     #
#    Updated: 2019/11/06 00:36:55 by fde-c                                     #
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


//3a047-2e347 2704c-ede08 df23e-a306a 7cd9a-f3dab 7a7eb-1ff49 3a77b-d5040 a3c51-598f6 0755b-c298d e35e1-e5ab3 79168-0ca94 b92e5-ea95c 171d3-2fc1c f9b3f-82b54 cae71-51fa2 f5d58-cdfe0 6ed5e-6d314
