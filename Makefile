NAME = so_long
MLX = MLX42/libmlx42.a
LIB = libft/libft.a

UNAME := $(shell uname)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c init.c map.c utils.c window.c hooks.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIB) $(MLX)
	gcc $(CFLAGS) $(OBJ) $(LIB) $(MLX) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"${HOME}/.brew/opt/glfw/lib/" -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB) : 
	make -C libft all

$(MLX) :
	#cmake -S ./mlx -B ./mlx/
	make -C mlx all

clean :
	@make -C libft clean
	@make -C mlx clean
	@rm -rf $(OBJ)

fclean : clean
	@make -C libft fclean
	#@rm -rf mlx/cmake_install.cmake
	#@rm -rf mlx/CMakeCache.txt
	@rm -rf $(NAME)

re: fclean all