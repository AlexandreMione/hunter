##
## EPITECH PROJECT, 2018
## Print_f
## File description:
## makefile
##

SRCM	=	iron_man.c

OBJM	=	$(SRCM:.c=.o)

CFLAGS	=   -Wall -Wextra -W

NAME	=   my_hunter   

.PHONY:	clean fclean re

all:	$(NAME)

$(NAME):    $(OBJM)
	gcc -l csfml-graphics -l csfml-audio -l csfml-system -o $(NAME) $(OBJM) $(CFLAGS)

clean:
	rm -f $(OBJM)
	rm -f */*.gc*

fclean: clean
	rm -f $(NAME)

re:	fclean all
