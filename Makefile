CC      =       gcc
NAME    =       list1

SRCS    =		main.c insert.c delete.c utils.c block.c quit.c

OBJS    =       $(SRCS:.c=.o)

all:    $(NAME)
				./$(NAME)

$(NAME):         $(OBJS)
	$(CC) ${CC_OPT} -o $(NAME)  $(OBJS)

clean:
	rm -f $(NAME) $(OBJS)

fclean: clean
	rm -f $(NAME)

re:     fclean all