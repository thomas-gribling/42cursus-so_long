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

FILES = main.c so_long.c map.c map_checker.c player.c \
		utils.c assets.c gnl/gnl.c gnl/gnl_utils.c
OBJECTS = $(addprefix $(SRCS), $(FILES:.c=.o))

BONUS_FILES = main_bonus.c so_long.c map.c map_checker.c player.c \
				utils.c assets.c gnl/gnl.c gnl/gnl_utils.c
BONUS_OBJECTS = $(addprefix $(SRCS), $(BONUS_FILES:.c=.o))

%.o: %.c
	@echo "$(YELLOW)Creating $@$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

mlx:
	make -sC $(MLX_PATH)
	
$(NAME): $(OBJECTS)
	@echo "$(YELLOW)Compiling $@$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_PATH)$(MLX_LIB) $(MLXFLAGS) -o $@ -I$(MLX_PATH) -I$(INCLUDE)
	@echo "$(BOLD_GREEN)Done!$(RESET)"

bonus: $(BONUS_OBJECTS)
	@echo "$(YELLOW)Compiling $(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_PATH)$(MLX_LIB) $(MLXFLAGS) -o $(NAME) -I$(MLX_PATH) -I$(INCLUDE)
	@echo "$(BOLD_GREEN)Done!$(RESET)"

clean:
	@echo Removing objects
	@rm -rf $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@echo Removing $(NAME)
	@rm -rf $(NAME)

re: fclean all