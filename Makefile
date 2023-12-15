NAME = so_long

SRCS = srcs/
INCLUDE = include/
MLX_PATH = mlx/
MLX_LIB = libmlx_Linux.a

CC = gcc
CFLAGS = 
MLXFLAGS = -lX11 -lXext

FILES = main.c map.c
OBJECTS = $(addprefix $(SRCS), $(FILES:.c=.o))

%.o: %.c
	@echo Creating $@
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

mlx:
	make -sC $(MLX_PATH)
	
$(NAME): $(OBJECTS)
	@echo Compiling $@...
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_PATH)$(MLX_LIB) $(MLXFLAGS) -o $@ -I$(MLX_PATH) -I$(INCLUDE)
	@echo Done!

clean:
	@echo Removing objects
	@rm -rf $(OBJECTS)

fclean: clean
	@echo Removing $(NAME)
	@rm -rf $(NAME)

re: fclean all