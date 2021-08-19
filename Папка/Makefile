SRC = *.c

OBJ = *.o


MLX = minilibx

INC_MLX = ./minilibx.h

CC = gcc

NAME = fractol

FLAGS = -lXext -lX11 -lmlx

all: $(NAME)

$(NAME):
	gcc $(SRC)  ./minilibx/libmlx_Linux.a -I. -I ./minilibx/ $(FLAGS) -o $(NAME)
clean:
	rm -f $(OBJ)
	rm -f $(NAME)

re: clean all
