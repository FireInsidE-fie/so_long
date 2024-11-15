NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm
RMFLAGS		=	-f
SRCDIR		=	src/
CFILES		=	$(SRCDIR)so_long.c\
OBJS		=	$(CFILES:.c=.o)
INCLDIR		=	include/
IFILES		=	so_long.h
LIBFTDIR	=	libft/
LIBFT		=	$(LIBFTDIR)libft.a

all:			$(NAME)


$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $^ -o $@

%.o:			%.c
				$(CC) $(CFLAGS) -g -c $^ -o $@

$(LIBFT):	 	$(LIBFTDIR)/*.c
				cd $(LIBFTDIR) && make

clean:
				$(RM) $(RMFLAGS) $(OBJS)
				cd $(LIBFTDIR) && make clean

fclean:			clean
				$(RM) $(RMFLAGS) $(NAME)
				cd $(LIBFTDIR) && make fclean

re:				fclean all


.PHONY:			all clean fclean re