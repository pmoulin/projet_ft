NAME = libftprintf.a

FT_PRINTF_SRC = srcs/ft_printf.c srcs/ft_dtoa.c srcs/parse_string.c \
				srcs/precision_for_oxdu.c srcs/ft_uitoa.c srcs/ft_atoi.c srcs/ft_isalnum.c srcs/ft_bzero.c srcs/ft_isalpha.c \
				srcs/ft_isascii.c srcs/ft_isdigit.c srcs/ft_isprint.c srcs/ft_itoa.c \
				srcs/ft_memalloc.c srcs/ft_memccpy.c srcs/ft_memchr.c srcs/ft_memcmp.c \
				srcs/ft_memcpy.c srcs/ft_memdel.c srcs/ft_memmove.c srcs/ft_memset.c \
				srcs/ft_putchar.c srcs/ft_putchar_fd.c srcs/ft_putendl.c \
				srcs/ft_putendl_fd.c srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_strcat.c \
				srcs/ft_putnbr_fd.c srcs/ft_putstr_fd.c srcs/ft_strchr.c srcs/ft_strclr.c\
				srcs/ft_strcmp.c srcs/ft_strcpy.c srcs/ft_strdel.c srcs/ft_strdup.c \
				srcs/ft_strequ.c srcs/ft_striter.c srcs/ft_striteri.c srcs/ft_strjoin.c \
				srcs/ft_strlcat.c srcs/ft_strlen.c srcs/ft_strmap.c srcs/ft_strmapi.c \
				srcs/ft_strncat.c srcs/ft_strncmp.c srcs/ft_strncpy.c srcs/ft_strnequ.c \
				srcs/ft_strnew.c srcs/ft_strnstr.c srcs/ft_strrchr.c srcs/ft_strsplit.c \
				srcs/ft_strstr.c srcs/ft_strsub.c srcs/ft_strtrim.c srcs/ft_tolower.c \
				srcs/ft_toupper.c srcs/ft_countwords.c srcs/ft_lstadd.c srcs/ft_lstdel.c \
				srcs/ft_lstiter.c srcs/ft_lstmap.c \
				srcs/ft_counttab.c srcs/ft_puttab.c srcs/ft_factorial.c srcs/ft_strrev.c \
				srcs/ft_power.c srcs/ft_get_next_line.c srcs/ft_ftoa.c \
				srcs/check_and_choice_flag.c srcs/join.c  \
				 srcs/preci_char.c srcs/ft_llitoa.c \
				srcs/ft_ullitoa.c srcs/ft_getwchar.c  \
				srcs/precision_and_lenght_for_p.c srcs/lenght_for_oxdu.c srcs/h_tag.c \
				srcs/precision_and_lenght_for_oxdu.c srcs/precision_and_lenght_for_oxdu_2.c \
				srcs/parse_preci_and_lenght.c srcs/parse_param_conv.c \
				srcs/choice_preci_and_lenght.c srcs/precision_and_langht_for_p_2.c \
				srcs/lenght_for_s.c srcs/putstr_like.c \
				srcs/flag_wchar_t.c srcs/flag_float.c srcs/flag_hexa.c srcs/flag_hexa_2.c\
				srcs/flag_char.c srcs/flag_faill.c srcs/flag_int.c srcs/flag_octal.c \
				srcs/flag_pointeur.c srcs/flag_unsi.c \
				srcs/choice_conv_param.c srcs/search_param.c \

OBJ = $(FT_PRINTF_SRC:.c=.o)

FT_PRINTF.INCLUDE = srcs/ft_printf.h srcs/libft.h

CC = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $@ $^
		ranlib $(NAME)

%.o: %.c
		$(CC) -o $@ -c $<

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)
		@echo "All Cleared"

re: fclean all

.PHONY: all
