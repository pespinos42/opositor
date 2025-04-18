NAME	= opositor

SRCS	= src/main.c \
src/gnl.c \
src/gnl_utils.c 

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	clear

clean:	
	$(RM) $(OBJS)
	clear

fclean:	clean
	$(RM) $(NAME)
	clear

re:	fclean all

.PHONY:	all clean fclean re
