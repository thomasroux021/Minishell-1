##
## EPITECH PROJECT, 2018
## Makeile
## File description:
## main Makefile
##

CC	=	gcc

RM	=	rm -f

NAME	=	mysh

CFLAGS	=	-I./include -I$(LIB_PATH)

SRCS	=	./src/main.c \
		./src/array.c \
		./src/parser.c \
		./src/get_next_line.c \
		./src/cd.c \
		./src/env.c

LIB_PATH=	src/lib/my/

OBJS	=	$(SRCS:.c=.o)

CFLAGS  +=      -W -Wall -Wextra

all	:	make_lib $(NAME)

make_lib:
		make -C $(LIB_PATH)

$(NAME)	:	$(OBJS)
	 $(CC) $(OBJS) -lm -o $(NAME) -I./include -L$(LIB_PATH) -lmy $(CFLAGS)

valgrind:	make_lib $(OBJS)
	 $(CC) -g $(SRCS) -lm -o $(NAME) -I./include -L$(LIB_PATH) -lmy $(CFLAGS)

clean	:
	$(RM) $(OBJS)
	make fclean -C $(LIB_PATH)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
