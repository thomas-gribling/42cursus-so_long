NAME = so_long

SRCS = srcs/
INCLUDE = include/
MLX_PATH = mlx/
MLX_LIB = libmlx_Linux.a

CC = gcc
CFLAGS = 
MLXFLAGS = -lX11 -lXext

FILES = main.c
OBJECTS = $(addprefix $(SRCS), $(FILES:.c=.o))

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

mlx:
	make -sC $(MLX_PATH)
	
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MLX_PATH)$(MLX_LIB) $(MLXFLAGS) -o $@ -I$(MLX_PATH) -I$(INCLUDE)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all