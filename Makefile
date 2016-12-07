CC =		gcc
FLAGS =		-Wall -Werror -Wextra
NAME =		fillit
HEAD =		fillit.h

SRCS = algo.c dimensions.c reset.c square_limit.c main.c \
split_count.c stack.c remove.c create_tab.c replace.c small.c tetri_list.c \
ft_print.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_strsub.c \
libft/ft_putnbr.c libft/ft_bzero.c libft/ft_memset.c libft/ft_strsplit.c \
check_tetri.c libft/ft_putendl.c

OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(LIB):
	make -C libft/ fclean
	make -C libft/

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

%.o:		%.c
	$(CC) $(FLAGS) -I $(HEAD) -o $@ -c $<

clean:
	/bin/rm -f $(OBJS)
	make -C libft/ fclean

fclean: 	clean
	/bin/rm -f $(NAME)

re: 		fclean all
