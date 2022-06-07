NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_strdup.c \
		ft_strtrim.c \
		ft_strjoin.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_memcpy.c \
		ft_split.c \
		ft_itoa.c \
		ft_put.c \
		ft_memset.c \
		ft_bzero.c \
		get_next_line.c \
		ft_puthexa.c \
		ft_putnumber.c \
		ft_putunumber.c \
		ft_printf.c \

OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	$(RM) $(OBJECTS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
