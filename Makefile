NAME = wolf3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o2 -funroll-loops -march=native -lpthread

GNL = gnl/get_next_line.c -I gnl

SRC = src/main.c src/make_env.c src/pixel_to_img.c src/line.c src/make_wolf.c src/make_vect.c src/floor.c src/mouse_and_key.c src/map.c src/wolf.c src/rot.c src/draw_vert.c src/dda.c src/textures.c src/draw_screen.c
FRAMEWORKS = -framework OpenGL -framework Appkit

INCLUDE = -I includes

INCLUDE_MLX = -I mlx
LINK_MLX = -L mlx -lmlx
MLX = $(INCLUDE_MLX) $(LINK_MLX)

INCLUDE_LIBFT = -I libft/includes
LINK_LIBFT = -L libft/ -lft
LIBFT = $(INCLUDE_LIBFT) $(LINK_LIBFT)

all: $(NAME)

libft.a:
	make -C libft re

mlx.a:
	make -C mlx re

$(NAME): libft.a mlx.a
	$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(INCLUDE) $(FRAMEWORKS) $(SRC) $(GNL) -o $(NAME)

clean:
	make -C libft fclean
	make -C mlx clean

fclean: clean
	rm -rf $(NAME)

re: clean all
