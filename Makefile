LB			= lib$(NAME).a
LOCLIBFT	= ./libft
LOCLHEADER	= ./header
SRCS		= $(wildcard src/ft_*.c)
OBJS		= $(SRCS:.c=.o)
NAME		= push_swap
UTIL		= ar
OPT			= rc
SUMM		= ranlib
RM			= rm -f
FLAG		= -Wall -Wextra -Werror -g
COMP		= cc
AR5			= $ARG

all:	$(NAME)

$(NAME):	main.c $(LB) $(LOCLHEADER)/ft_$(NAME).h
	$(COMP) $(FLAG) -o $(NAME) main.c -L. -l$(NAME)

$(LB):	$(LOCLIBFT)/libft.a $(OBJS) $(LOCLHEADER)/ft_$(NAME).h
	cp $(LOCLIBFT)/libft.a $(LB)
	$(UTIL) $(OPT) $(LB) $(OBJS)
	$(SUMM) $(LB)

$(LOCLIBFT)/libft.a:
	make -C $(LOCLIBFT)

clean:
	make clean -C $(LOCLIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LOCLIBFT)
	$(RM) $(NAME) $(LB)

re: fclean all

list:
	ls -la

run: $(NAME)
	./$(NAME) $5

.PRONH: all $(LB) $(NAME) $(LOCLIBFT)/libft.a clean fclean re list run

###	ARG=$(shuf -i 1-2147483647 -n 10 | tr '\n' ' ') && ./push_swap $ARG
### ARG=$(echo {1..500}$'\n' | sort -R | tr "\n" " ") && ./push_swap $ARG
