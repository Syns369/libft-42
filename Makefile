PRINTF_DIR = ft_printf/
PRINTF_FILE = libftprintf.a
PRINTF = $(PRINTF_DIR)$(PRINTF_FILE)

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_substr.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strcmp.c \

BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(BONUS:.c=.o)
OBJS_PRINTF = $(PRINTF_DIR)\ft_printf.o\
				$(PRINTF_DIR)\ft_putnbr.o\

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all : $(NAME)

$(PRINTF) :
	@make all -C $(PRINTF_DIR)

$(NAME) : $(OBJS) $(PRINTF)
	ar rcs $(NAME) $(OBJS) $(OBJS_PRINTF)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -o $@ -c $<

bonus : $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean :
	rm -f $(OBJS) $(OBJS_BONUS)
	make clean -C $(PRINTF_DIR)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_DIR)

re : fclean all

.PHONY : all clean fclean re bonus