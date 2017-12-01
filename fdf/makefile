SRC = srcs/main.c srcs/ft_alloc_parse.c \
		srcs/ft_check_map.c srcs/ft_error.c\
	  	srcs/ft_read_file.c srcs/ft_trace.c srcs/ft_matrice.c srcs/ft_write_line.c \
	 	srcs/ft_change_pos.c srcs/ft_change_size.c srcs/ft_gen_maps.c

OBJ = $(SRC:.c=.o)

LIB = libft/libft.a

LIBMLX = minilibx_macos/libmlx.a

INC = libft

MLX = minilibx/

NAME = fdf

FLAGS = -Wall -Wextra -Werror

XFLAG = -framework OpenGL -framework AppKit

CC = clang

all: libft mlx $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(FLAGS) -o $@ $^ $(XFLAG) $(LIB) $(LIBMLX)

%.o: %.c
		@$(CC) $(FLAGS) -o $@ -c $<

mlx:
		@make -C minilibx_macos/

libft:
		@make -C libft/

clean:
		@rm -f $(OBJ)
			@make -C libft/ clean

fclean: clean
		@rm -f $(NAME)
			@make -C libft/ fclean

re: fclean all

.PHONY: libft
