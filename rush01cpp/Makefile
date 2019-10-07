NAME = ft_gkrellm

SRC   = main.cpp \
DateModule.cpp\
GraphicDisplay.cpp\
NameModule.cpp\
NcurseDisplay.cpp\
cpuModule.cpp \
netModule.cpp\
osModule.cpp \
RAMModule.cpp

GCC   =clang++
FLAGS =-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) Makefile
	$(GCC) $(FLAGS) $(SRC) -o $(NAME) lib/*

clean:

fclean: clean
	rm -f $(NAME)

re:		fclean all


.PHONY: all clean fclean re
