NAME = FDF

MLX_FLAGS = -L minilibx-linux -lmlx_Linux -lmlx -lXext -lX11
MLX_DIR	= minilibx-linux
MLX_A = minilibx-linux/libmlx_Linux.a
CC = gcc

CFLAGS = -Werror -Wall -Wextra

RM = rm -rf

SRCS =  srcs/main.c \
		srcs/error.c \
		srcs/init_matrix.c \
		srcs/matrix_utils.c \
		srcs/draw_map.c \
		srcs/key_manager.c \
		srcs/window_manager.c \
		srcs/draw_utils.c \

OBJS    = ${SRCS:.c=.o}

LIBFT_DIR = libft
LIBFT_A = libft/libft.a
_CLEAR	= \033[0K\r\c
_OK	= [\033[32mOK\033[0m]

all : $(LIBFT_A) $(MLX_A) $(NAME)

$(LIBFT_A): libft/libft.h
	@echo "[..] libft... compiling \r\c"
	@$(MAKE) -C $(LIBFT_DIR) -s
	@echo "$(_CLEAR)"

$(MLX_A):
	@echo "[..] mlx... compiling \r\c"
	@$(MAKE) -C $(MLX_DIR) -s
	@echo "$(_CLEAR)"

${NAME}: ${OBJS} $(LIBFT_A)
	@${CC} ${CFLAGS} -g3 -I include -I libft/ -o $@ $^ $(MLX_FLAGS) -Llibft -lft -lm
	@echo "$(_OK) $(NAME) compiled"

%.o: %.c  include/fdf.h libft/libft.h
	@echo "[..] $(NAME_SHORT)... compiling $*.c\r\c"
	@${CC} ${CFLAGS} -g3 -Iinclude -Ilibft/ -Iminilibx-linux/ -c $< -o $@
	@echo "$(_CLEAR)"

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean -s
	@$(MAKE) -C $(MLX_DIR) clean -s
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean -s
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

re : fclean all

.PHONY: all clean fclean re libft

