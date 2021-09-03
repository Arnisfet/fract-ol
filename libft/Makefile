SRCS	=	ft_atoi.c	ft_bzero.c	ft_calloc.c	ft_count_words.c	ft_isalnum.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c	ft_itoa.c	ft_memccpy.c	ft_memchr.c	ft_memcmp.c	ft_memcpy.c	ft_memmove.c	ft_memset.c	ft_mystrncpy.c	ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c	ft_strchr.c	ft_strdup.c	ft_strjoin.c	ft_strlcat.c	ft_strlcpy.c	ft_strlen.c	ft_strmapi.c	ft_strncmp.c	ft_strndup.c	ft_strnstr.c	ft_strrchr.c	ft_substr.c	ft_tolower.c	ft_toupper.c	ft_strtrim.c	ft_strcmp.c	ft_atof.c

CFLAGS	=	-Wall -Werror -Wextra

OBJS	=	$(SRCS:.c=.o)

NAME	=	libft.a

FLAGS	=	-Wall -Werror -Wextra

HEADER	=	-c -I.

all:	$(NAME)



$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "\t\t\t\t\033[0;42mCompile is ready\n"

%.o:	%.c
	@gcc $(FLAGS) -c $< -o $@
	@echo "\t\t\t\t\033[0;31mCompile $@"

clean:
	@rm -f $(OBJS)
	@echo "\t\t\t\t\033[0;31mDelete all objects"

fclean: clean
	@rm -f $(NAME)
	@echo "\t\t\t\t\033[0;31mDelete libft.a"

re:	fclean all
