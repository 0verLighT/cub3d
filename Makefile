CC			= cc
CFLAGS		= -MP -MMD -Wall -Werror -Wextra -g
NAME		= cub3d
BUILD_DIR	= builddir/
MLX_DIR		= ./subprojects/mlx
LIBFT_DIR	= ./subprojects/libft

SOURCES = src/main.c
OBJS = $(SOURCES:%.c=$(BUILD_DIR)%.o)
DEPS = $(SOURCES:%.c=$(BUILD_DIR)%.d)

MLX			= ./subprojects/mlx/libmlx.so
LIBFT		= ./subprojects/libft/libft.a

INCLUDES	= -Iincludes -I$(MLX_DIR)/includes -I$(LIBFT_DIR)
LDFLAGS		= -L$(MLX_DIR) -L$(LIBFT_DIR) -Wl,-rpath,$($(MLX_DIR))
LDLIBS		= -lmlx -lft -lm -lSDL2

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) -j8

$(MLX):
	$(MAKE) -C $(MLX_DIR) -j8

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

re: fclean all

clean:
	rm -rf builddir/
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean $(LIB_FCLEAN)
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) fclean

.PHONY: all re fclean clean

-include $(DEPS)