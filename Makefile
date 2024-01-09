NAME = so_long

BOLD_GREEN		= \033[32;01m
YELLOW			= \033[0;33m
RESET			= \033[0m

SRCS = srcs/
INCLUDE = include/
MLX_PATH = mlx/
MLX_LIB = libmlx_Linux.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lm
MLXFLAGS = -lX11 -lXext

FILES = main.c so_long.c player.c assets.c \
		map_1.c map_2.c map_3.c utils_1.c utils_2.c \
		gnl/gnl.c gnl/gnl_utils.c \
		bonus/moves_bonus.c bonus/utils_bonus.c

OBJECTS = $(addprefix $(SRCS), $(FILES:.c=.o))

BONUS_MODE = 0

%.o: %.c
	@echo "$(YELLOW)Creating $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -D BONUS_MODE=$(BONUS_MODE)

all: $(NAME)

mlx:
	make -sC $(MLX_PATH)
	
$(NAME): $(OBJECTS)
	@echo "$(YELLOW)Compiling $@$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_PATH)$(MLX_LIB) $(MLXFLAGS) -o $@ -I$(MLX_PATH) -I$(INCLUDE)
	@echo "$(BOLD_GREEN)Done!$(RESET)"

bonus: BONUS_MODE = 1
bonus: clean $(NAME)

clean:
	@echo Removing objects
	@rm -rf $(OBJECTS)

fclean: clean
	@echo Removing $(NAME)
	@rm -rf $(NAME)

re: fclean all