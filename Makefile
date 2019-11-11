# **************************************************************************** #
#                                                                              #
#                                                                              #
#    Makefile                                                                  #
#                                                   ||||||:||||::|||:|:|||:    #
#    By: |||||| <::::::>                            ::||:||:|::||::|:||::::    #
#                                                   |:|:|:::|::|::::::|||||    #
#    Created: 2019/11/08 13:55:06 by ||||||                                    #
#    Updated: 2019/11/08 13:55:10 by ||||||                                    #
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

