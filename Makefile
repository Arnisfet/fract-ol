SRC_FRC	=	 ./sources/another.c	./sources/burning_ship.c	./sources/color.c	\
	./sources/Get_real.c	./sources/hooks.c	./sources/julia.c	\
	./sources/keyboard_hooks.c	./sources/main.c	./sources/mandelbrot.c	\
	./sources/mouse_hooks.c	./sources/my_frctl_or_triple_m.c	./sources/serpinskiy.c		

OBJ_NAME			=	$(SRC_FRC:.c=.o)

OBJ_DIR		=	./obj/

INC_MLX_MAC = -I includes/mlx.h

INC_LIB = -I libft/libft.h

INC_HEAD = -I. 

WWW	=	-Wall -Werror -Wextra

CC = gcc

OBJ		=	$(addprefix $(OBJ_DIR), $(OBJ_NAME))

NAME = fractol

LINX_LIB = libmlx_Linux.a

MLX		=	mlx/libmlx.a

LIBFT = libft/libft.a

FLAGS_MAC = -lmlx -framework OpenGL -framework AppKit

FLAGS = -lXext -lX11

all: $(NAME)

$(NAME):	$(OBJ_NAME)
	@make -C libft
	@make -C mlx
	@echo "\t\t\t\t\033[0;31mLibft and MLX is ready!"
	@gcc $(OBJ_NAME) $(LIBFT) $(MLX) $(FLAGS_MAC) -o $(NAME) $(WWW)
	@echo "\t\t\t\t\033[0;31mMake fractol.exe\n"

%.o:	./sources%.c
	@gcc -c -I. $(INC_MLX_MAC) $(INC_LIB) $(WWW) $< -o $@
	@echo "\t\t\t\t\033[0;34m Compile $@"

clean:
	@make clean -C libft
	@rm -f $(OBJ_NAME)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@echo "\t\t\t\t\033[0;31mDeleate fractol.exe"
	

re: fclean all
