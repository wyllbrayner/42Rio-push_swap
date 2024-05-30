LB			= lib$(NAME).a
LOCLIBFT	= ./libft
LOCLHEADER	= ./header
SRCS		= src/ft_actions_push.c src/ft_actions_reverse.c src/ft_actions_rotato.c \
				src/ft_actions_swap.c src/ft_push_swap.c src/ft_split_input.c \
				src/ft_sort_algorithm_easy.c src/ft_sort_algorithm_mediun.c \
				src/ft_sort_algorithm_mediun_aux.c src/ft_sort_algorithm_hard.c \
				src/ft_structs_1.c src/ft_structs_2.c src/ft_structs_3.c \
				src/ft_utils_1.c src/ft_utils_2.c src/ft_utils_3.c \
				src/ft_valid_input.c src/ft_valid_input_aux.c
OBJS		= $(SRCS:.c=.o)
NAME		= push_swap
UTIL		= ar
OPT			= rc
SUMM		= ranlib
RM			= rm -f
FLAG		= -Wall -Wextra -Werror -g
COMP		= cc

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

norminette:
	norminette

norminetteh:
	norminette -R CheckDefine

.PRONH: all $(NAME) $(LB) $(LOCLIBFT)/libft.a clean fclean re list norminette norminetteh
