NAME		= push_swap

LOCLIBFT	= ./libft
SRCSDIR		= ./src/
SRCS		= main.c ft_actions_push.c ft_actions_reverse.c \
				ft_actions_rotato.c ft_actions_swap.c ft_push_swap.c \
				ft_split_input.c ft_sort_algorithm_easy.c \
				ft_sort_algorithm_mediun.c ft_sort_algorithm_mediun_aux.c \
				ft_sort_algorithm_hard.c ft_structs_1.c ft_structs_2.c \
				ft_structs_3.c ft_utils_1.c ft_utils_2.c ft_utils_3.c \
				ft_valid_input.c ft_valid_input_aux.c
SRCS		:= $(addprefix $(SRCSDIR), $(notdir $(SRCS)))
OBJDIR		= ./obj/
OBJS		= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

RM			= rm -rf
FLAG		= -Wall -Wextra -Werror
COMP		= cc

YELLOW		= \033[33m
GREEN		= \033[32m
RESET		= \033[0m

all:	$(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(OBJDIR)
	@$(COMP) $(FLAG) -c $< -o $@
	@echo -n "#"

$(NAME):	$(LOCLIBFT)/libft.a $(OBJS)
	@$(COMP) $(FLAG) -o $(NAME) $(OBJS) -L$(LOCLIBFT) -lft
	@echo "\n\$(GREEN) 💯 | $(NAME) created.$(RESET)"

$(LOCLIBFT)/libft.a:
	make -C $(LOCLIBFT)

clean:
	make clean -C $(LOCLIBFT)
	$(RM) $(OBJDIR)
	@echo "$(YELLOW) 🧹 | $(NAME) cleaned.$(RESET)"

fclean: clean
	make fclean -C $(LOCLIBFT)
	$(RM) $(NAME)
	@echo "$(YELLOW) 🧹 | $(NAME) all cleaned.$(RESET)"

re: fclean all

norm:
	norminette

normh:
	norminette -R CheckDefine

.PRONH: all $(NAME) $(LOCLIBFT)/libft.a clean fclean re norm normh
