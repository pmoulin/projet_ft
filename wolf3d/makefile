NAME = WOLF3D

WOLF3D.SRC = srcs/main.c srcs/parseur.c srcs/read_files.c srcs/create_win_img.c\
						 srcs/init_struct.c srcs/edit_color.c srcs/gen_map.c srcs/key_hook.c\
						 srcs/detec_mur.c srcs/aff_mur.c srcs/move_cam.c srcs/gen_mini_map.c\
						 srcs/gen_menu_down.c srcs/weapon.c srcs/weapon_select.c srcs/ft_error.c \
						 srcs/check_map.c srcs/cordo_start.c

OBJ = $(WOLF3D.SRC:.c=.o)

LIB = libft/libft.a

WOLF3D.INCLUDE = includes/wolf.h

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
		@echo "\\0033[32mWOLF3D 1OBJ cleared\\0033[0m"
		@make -C minilibx_macos/

libft:
		@echo "\\0033[32mWOLF3D 3OBJ cleared\\0033[0m"
		make -C libft/

clean:
		@rm -f $(OBJ)
		make -C minilibx_macos/ clean
		make -C libft/ clean

fclean: clean
		@rm -f $(NAME)
		make -C libft/ fclean
		@echo "All Cleared"

re: fclean all

.PHONY : libft
