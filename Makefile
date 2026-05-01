CC			= cc
MAKE		= make --no-print-directory
CFLAGS		= -MP -MMD -Wall -Werror -Wextra -g
NAME		= cub3D
BUILD_DIR	= builddir/
MLX_DIR		= ./subprojects/mlx
LIBFT_DIR	= ./subprojects/libft

SRC_DIR = src
SRC = main.c parser.c
SOURCES = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(SOURCES:%.c=$(BUILD_DIR)%.o)
DEPS = $(SOURCES:%.c=$(BUILD_DIR)%.d)

MLX			= ./subprojects/mlx/libmlx.so
LIBFT		= ./subprojects/libft/libft.a

INCLUDES	= -Iincludes -I$(MLX_DIR)/includes -I$(LIBFT_DIR)/includes
LDFLAGS		= -L$(MLX_DIR) -L$(LIBFT_DIR) -Wl,-rpath,$($(MLX_DIR))
LDLIBS		= -lmlx -lft -lm -lSDL2

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) -j8

$(MLX):
	@$(MAKE) -C $(MLX_DIR) -j8

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "\033[1;32m$(NAME) created.\033[0m"

re: fclean all

clean:
	@rm -rf builddir/
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "\033[1;32mObjects cleaned.\033[0m"

fclean: clean $(LIB_FCLEAN)
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean
	@echo "\033[1;32mEverything cleaned.\033[0m"

.PHONY: all re fclean clean

-include $(DEPS)
