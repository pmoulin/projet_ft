ifeq ($(HOSTTYPE),)
    HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME 		= libft_malloc_$(HOSTTYPE).so

MKDIR		= mkdir -p
LS			= ls -1
GREP		= grep
CC			= gcc -Wall -Werror -Wextra

DSRC		= src


DOBJ		= obj
DINC		= includes

FSRC		:= $(shell $(LS) $(DSRC) | $(GREP) \.c$)
FOBJ		:= $(FSRC:.c=.o)

INCLUDE		= $(DINC)/ft_malloc.h

FSRC		:= $(addprefix $(DSRC)/, $(FSRC))
FOBJ		:= $(addprefix $(DOBJ)/, $(FOBJ))

all: $(FOBJ) $(NAME)

$(NAME): $(FOBJ)
		@echo "\\0033[32mSTART COMPIL\\0033[0m"
		$(CC) -I $(INCLUDE) -shared -o $(NAME) $(FOBJ)
		$(shell ln -s $(NAME) libft_malloc.so)
		@echo "\\0033[32mCOMPIL FINISH\\0033[0m"

$(DOBJ)/%.o: $(DSRC)/%.c 
		$(MKDIR) $(DOBJ)
			$(CC) -c $< -o $@

clean:
		@rm -rf $(DOBJ)

fclean: clean
		@rm -f $(NAME)
		@rm -f libft_malloc.so
		@echo "All Cleared"

re: fclean all
	
