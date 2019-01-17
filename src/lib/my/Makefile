##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## lib Makefile
##

RM	=	rm -f

LIB	=	libmy.a

SRCS	=	my_strcmp.c \
		my_put_nbr.c \
		my_strlowcase.c \
		my_compute_power_rec.c \
		my_strdup.c \
		my_putstr.c \
		my_strcpy.c \
		my_strncat.c \
		my_revstr.c \
		my_str_isalpha.c \
		my_strncmp.c \
		my_find_prime_sup.c \
		my_showmem.c \
		my_str_islower.c \
		my_strncpy.c \
		my_getnbr.c \
		my_showstr.c \
		my_str_isnum.c \
		my_strstr.c \
		my_isneg.c \
		my_sort_int_array.c \
		my_str_isprintable.c \
		my_strupcase.c \
		my_is_prime.c \
		my_strcapitalize.c \
		my_str_isupper.c \
		my_swap.c \
		my_putchar.c \
		my_strcat.c \
		my_strlen.c	\
		my_index_of.c

OBJS    =       $(SRCS:.c=.o)

all:	lib

lib: 	$(OBJS)
	ar rc $(LIB) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIB)

re: fclean all

.PHONY: all clean fclean re
