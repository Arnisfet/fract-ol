SRC = *.c

OBJ = $(SRC:.c=.o)

INC_MLX_MAC = -I includes/mlx.h

INC_LIB = -I libft/libft.h

INC_HEAD = -I. 

CC = gcc

NAME = fractol

LINX_LIB = libmlx_Linux.a

LIBFT = libft/libft.a

FLAGS_MAC = -lmlx -framework OpenGL -framework AppKit

FLAGS = -lXext -lX11

all: $(NAME)

$(NAME):
	@make -C libft
	@echo "\t\t\t\t\033[0;41mLibft is ready!"
	@gcc $(SRC) $(INC_LIB) $(LIBFT) $(INC_HEAD) $(INC_MLX_MAC) $(FLAGS_MAC) -o $(NAME)
	@echo "\t\t\t\t\033[0;31mMake fractol.exe"
clean:
	@rm -f $(OBJ)
	@rm -f ./libft/$(OBJ)
	@echo "\t\t\t\t\033[0;31mClean"

fclean: clean
	@rm -f $(NAME)
	@rm -f ./libft/libft.a
	@echo "\t\t\t\t\033[0;31m Deleate fractol.exe"
	

re: fclean all
