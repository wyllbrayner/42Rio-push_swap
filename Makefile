LB			= lib$(NAME).a
LOCLIBFT	= ./libft
LOCLHEADER	= ./header
SRCSDIR		= ./src/
SRCS		= ft_actions_push.c ft_actions_reverse.c ft_actions_rotato.c \
				ft_actions_swap.c ft_push_swap.c ft_split_input.c \
				ft_sort_algorithm_easy.c ft_sort_algorithm_mediun.c \
				ft_sort_algorithm_mediun_aux.c ft_sort_algorithm_hard.c \
				ft_structs_1.c ft_structs_2.c ft_structs_3.c \
				ft_utils_1.c ft_utils_2.c ft_utils_3.c \
				ft_valid_input.c ft_valid_input_aux.c
SRCS		:= $(addprefix $(SRCSDIR), $(notdir $(SRCS)))
OBJDIR		= ./obj/
OBJS		= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))
NAME		= push_swap
UTIL		= ar
OPT			= rc
SUMM		= ranlib
RM			= rm -rf
FLAG		= -Wall -Wextra -Werror -g
COMP		= cc

all:	$(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(OBJDIR)
	$(COMP) $(FLAG) -c $< -o $@
	#echo -n "#"

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
	$(RM) $(OBJDIR)

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
