NAME = so_long

BOLD_GREEN		= \033[32;01m
BOLD_CYAN		= \033[36;01m
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
RESET			= \033[0m

SRCS = srcs/
INCLUDE = include/
MLX_PATH = mlx/
MLX_LIB = libmlx_Linux.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -lm
MLXFLAGS = -lX11 -lXext

FILES = main.c so_long.c player_1.c player_2.c assets.c \
		map_1.c map_2.c map_3.c utils_1.c utils_2.c \
		gnl/gnl.c gnl/gnl_utils.c \
		bonus/enemies_1.c bonus/enemies_2.c bonus/ft_split.c \
		bonus/utils_bonus.c bonus/bonus_1.c bonus/bonus_2.c

OBJECTS = $(addprefix $(SRCS), $(FILES:.c=.o))

BONUS_MODE = 0

%.o: %.c
	@echo "$(BOLD_CYAN)$(NAME) $(RESET)[$(GREEN)$@$(RESET)] : $(YELLOW)Creating object$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ -D BONUS_MODE=$(BONUS_MODE)

all: mlx $(NAME)

mlx:
	@make -sC $(MLX_PATH)

$(NAME): $(OBJECTS)
	@echo "$(BOLD_CYAN)$(NAME) $(RESET)[$(GREEN)$@$(RESET)] : $(YELLOW)Compiling $@$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX_PATH)$(MLX_LIB) $(MLXFLAGS) -o $@ -I$(MLX_PATH) -I$(INCLUDE)
	@echo "$(BOLD_GREEN)Done!$(RESET)"

bonus: BONUS_MODE = 1
bonus: clean mlx $(NAME)

clean:
	@echo "$(BOLD_CYAN)$(NAME) $(RESET)[$(GREEN)$@$(RESET)] : Removing objects"
	@rm -rf $(OBJECTS)

fclean: clean
	@echo "$(BOLD_CYAN)$(NAME) $(RESET)[$(GREEN)$@$(RESET)] : Removing $(NAME)"
	@rm -rf $(NAME)
	@make clean -sC $(MLX_PATH)

re: fclean all

.PHONY: mlx