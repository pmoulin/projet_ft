NAME = FRACTOL

FRACTOL.SRC = srcs/main.c srcs/create_win.c srcs/key_hook.c srcs/edit_color.c \
							srcs/gen_frac.c srcs/mandel.c srcs/julia.c srcs/init.c \
							srcs/burn_ship.c srcs/fractal.c srcs/zoom.c srcs/modif_pos.c \
							srcs/help.c srcs/reset.c srcs/error.c srcs/key_hook2.c

OBJ = $(FRACTOL.SRC:.c=.o)

LIB = libft/libft.a

FRACTOL.INCLUDE = includes/fractol.h

INC = libft

FLAGS = -Wall -Wextra -Werror

LIBMLX = minilibx_macos/libmlx.a

XFLAG = -framework OpenGL -framework AppKit

CC = gcc

all: libft mlx $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) -o $@ $^ $(XFLAG) $(LIB) $(LIBMLX)

%.o: %.c
		$(CC) $(FLAGS) -o $@ -c $<

mlx:
		@echo "\\0033[32mMAKE MLX\\0033[0m"
		make -C minilibx_macos/

libft:
		@echo "\\0033[32mMAKE LIBFT\\0033[0m"
		make -C libft/

clean:
		rm -f $(OBJ)
		@echo "\\0033[32mCLEAN LIBFT\\0033[0m"
		make -C libft/ clean
		make -C minilibx_macos/ clean
fclean: clean
		rm -f $(NAME)
		make -C libft/ fclean
		@echo "All Cleared"

re: fclean all

.PHONY : libft
