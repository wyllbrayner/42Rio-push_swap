NAME = libft.a
SRCS =	ft_putendl_fd.c		ft_strncmp.c \
ft_putnbr_fd.c		ft_strnstr.c \
ft_atoi.c		ft_putstr_fd.c		ft_strrchr.c \
ft_bzero.c		ft_split.c		ft_strtrim.c \
ft_calloc.c		ft_strchr.c		ft_substr.c \
ft_isalnum.c		ft_strdup.c		ft_tolower.c \
ft_isalpha.c		ft_memchr.c		ft_striteri.c		ft_toupper.c \
ft_isascii.c		ft_memcmp.c		ft_strjoin.c  \
ft_isdigit.c		ft_memcpy.c		ft_strlcat.c  \
ft_isprint.c		ft_memmove.c		ft_strlcpy.c \
ft_itoa.c		ft_memset.c		ft_strlen.c \
ft_putchar_fd.c		ft_strmapi.c \

SRCBONUS = ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(SRCBONUS:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

bonus: $(OBJS) $(OBJSBONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJSBONUS) 

clean: 
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean 
		$(RM) $(NAME)

re: fclean all



