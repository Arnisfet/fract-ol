SRC = *.c

OBJ = *.o

INC_MLX_MAC = -I includes/mlx.h

INC_LIB = -I includes/libft.h

INC_HEAD = -I. 

CC = gcc

NAME = fractol

FLAGS_MAC = -lmlx -framework OpenGL -framework AppKit

FLAGS = -lXext -lX11

all: $(NAME)

$(NAME):
	gcc $(SRC) libmlx_Linux.a $(INC_LIB) $(INC_HEAD) $(INC_MLX_MAC) $(FLAGS) -o $(NAME)
clean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: clean all
