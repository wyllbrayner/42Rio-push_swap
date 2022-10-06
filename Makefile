NAME		= lib$(PROJ).a
LOCLIBFT	= ./libft
LOCLHEADER	= ./header
SRCS		= $(wildcard src/ft_*.c)
OBJS		= $(SRCS:.c=.o)
PROJ		= push_swap
UTIL		= ar
OPT			= rc
SUMM		= ranlib
RM			= rm -f
FLAG		= -Wall -Wextra -Werror
COMP		= cc

all:	$(NAME)

$(NAME):	$(LOCLIBFT)/libft.a $(OBJS) $(LOCLHEADER)/ft_$(PROJ).h
	cp $(LOCLIBFT)/libft.a $(NAME)
	$(UTIL) $(OPT) $(NAME) $(OBJS)
	$(SUMM) $(NAME)

$(LOCLIBFT)/libft.a:
	make -C $(LOCLIBFT)

clean:
	make clean -C $(LOCLIBFT)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LOCLIBFT)
	$(RM) $(NAME)

re: fclean all

list:
	ls -la

$(PROJ):	main.c $(NAME) $(LOCLHEADER)/ft_$(PROJ).h
	$(COMP) $(FLAG) -o $(PROJ) main.c -L. -l$(PROJ)

run: $(PROJ)
	./$(PROJ)

fclean2: clean
	make fclean -C $(LOCLIBFT)
	$(RM) $(NAME) $(PROJ)

###	ARG=$(shuf -i 1-1000000 -n 10 | tr '\n' ' ') && ./push_swap $ARG

.PRONH: all $(NAME) clean fclean re list libft$(PROJ).out run fclean$(PROJ)


