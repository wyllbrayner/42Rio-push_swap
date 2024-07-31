NAME		= libft
OBJDIR		= ./obj/
SRCS		= 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
				ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCSBONUS 	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS		= $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))
OBJSBONUS	= $(addprefix $(OBJDIR), $(notdir $(SRCSBONUS:.c=.o)))
PROJ		= ft
RM			= rm -rf
UTIL		= ar
OPT			= rc
SUMM		= ranlib
COMP		= cc
FLAG		= -Wall -Wextra -Werror
LOCLIB		= .
YELLOW		= \033[33m
GREEN		= \033[32m
RESET		= \033[0m

all:	$(NAME)

# .c.o:
# 	@${COMP} ${FLAG} -c $< -o ${<:.c=.o}
# 	@echo -n "#"

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(COMP) $(FLAG) -c $< -o $@
	@echo -n "#"

$(NAME):	$(OBJS)
	@$(UTIL) $(OPT) $(NAME).a $(OBJS)
	@$(SUMM) $(NAME).a
	@echo "\n\$(GREEN) 💯 | $(NAME) default created.$(RESET)"

bonus:	$(NAME) $(OBJSBONUS)
	@$(UTIL) $(OPT) $(NAME).a $(OBJSBONUS)
	@$(SUMM) $(NAME).a
	@echo "\n\$(GREEN) 💯 | $(NAME) bonus created.$(RESET)"

clean:
	@$(RM) $(OBJDIR)
	@echo "$(YELLOW) 🧹 | $(NAME) cleaned.$(RESET)"

fclean: clean
	@$(RM) $(NAME).a
	@echo "$(YELLOW) 🌪️ | $(NAME) all cleaned.$(RESET)"

re: fclean all

reb: re bonus

norm:
	@norminette -R CheckDefineForbiddenSourceHeader $(SRCS) $(NAME).h $(SRCSBONUS) $(NAME)_bonus.h

.PRONH: all $(NAME) bonus clean fclean re reb norm