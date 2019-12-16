# ********************************************* #
#                                               #
#                      |:||:||::||:|:|||:||||:  #
#  Makefile            |::|||::|:|:|:::||:::|:  #
#                      :|::::||||||::::::|:||:  #
#      |:|:|: <|:|:|:>                          #
#                                               #
#  C20191216161355 |:|:|:                       #
#  U20191216162723 ::::::                       #
#                                               #
# ********************************************* #

NAME = ./x

CC = gcc $(DEFBUG)

HARD = -Wall -Werror -Wextra
VERBOSE = -v
DEBUG = -g

SRCS =		main.c		 \
			random.c	 \
			debug.c		 \
			brain.c		 \
			genome.c	 \
			helper.c	 \
			thoughts.c

OBJS = $(SRCS:.c=.o)

HEADER =	header.h	 \
			typedefs.h	 \
			helperdefs.h \
			defs.h

all:	$(HEADER) $(NAME)
	$(NAME)

$(NAME):	$(HEADER) $(OBJS)
	$(CC) $(HARD) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean
	make all

v:	$(OBJS)
	$(CC) $(HARD) $(VERBOSE) \
		$(OBJS) -o $(NAME)

soft:	$(HEADER) $(OBJS)
	$(CC) $(VERBOSE) $(OBJS) -o $(NAME)
	$(NAME)
