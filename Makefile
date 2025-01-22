NAME			=	so_long
NAME_BONUS		=	so_long_bonus
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm
RMFLAGS			=	-f
SRCDIR			=	src/
CFILES			=	$(SRCDIR)so_long.c \
					$(SRCDIR)utils.c \
					$(SRCDIR)init.c \
					$(SRCDIR)input.c \
					$(SRCDIR)flood.c \
					$(SRCDIR)map.c
SRCDIR_BONUS	=	src_bonus/
CFILES_BONUS	=	$(SRCDIR_BONUS)so_long_bonus.c \
					$(SRCDIR_BONUS)utils_bonus.c \
					$(SRCDIR_BONUS)init_bonus.c \
					$(SRCDIR_BONUS)input_bonus.c \
					$(SRCDIR_BONUS)flood_bonus.c \
					$(SRCDIR_BONUS)map_bonus.c \
					$(SRCDIR_BONUS)enemy_bonus.c \
					$(SRCDIR_BONUS)score_bonus.c
OBJS			=	$(CFILES:.c=.o)
OBJS_BONUS		=	$(CFILES_BONUS:.c=.o)
LIBFTDIR		=	libftprintf/
LIBFT			=	$(LIBFTDIR)libftprintf.a

all:				$(NAME)


$(NAME):			$(OBJS) $(LIBFT)
					$(CC) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $@

%.o:				%.c
					$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -g -c $^ -o $@

$(LIBFT):			$(LIBFTDIR)/*.c
					cd $(LIBFTDIR) && make

clean:
					$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)
					cd $(LIBFTDIR) && make clean
fclean:				clean
					$(RM) $(RMFLAGS) $(NAME)
					cd $(LIBFTDIR) && make fclean
re:					fclean all


bonus:				$(NAME_BONUS)


$(NAME_BONUS):		$(OBJS_BONUS) $(LIBFT)
					$(CC) $^ -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $@

.PHONY:				all clean fclean re bonus
