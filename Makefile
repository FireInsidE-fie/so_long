NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm
RMFLAGS		=	-f
SRCDIR		=	src/
CFILES		=	$(SRCDIR)so_long.c
OBJS		=	$(CFILES:.c=.o)
INCLDIR		=	include/
IFILES		=	$(INCLDIR)so_long.h
LIBFTDIR	=	libft/
LIBFT		=	$(LIBFTDIR)libft.a

all:			$(NAME)


$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXest -lX11 -lm -lz -o $@

%.o:			%.c
				$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $^ -o $@

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