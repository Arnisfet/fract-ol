SRC = *.c

OBJ = *.o

MLX_MAC = -L /usr/local/lib/

INC_MLX_MAC = -I /usr/local/include/mlx.h

CC = gcc

NAME = fractol

FLAGS_MAC = -lmlx -framework OpenGL -framework AppKit

FLAGS = -lXext -lX11 -lmlx

all: $(NAME)

$(NAME):
	gcc $(SRC)  $(MLX_MAC) -I. $(INC_MLX_MAC) $(FLAGS_MAC) -o $(NAME)
clean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: clean all
