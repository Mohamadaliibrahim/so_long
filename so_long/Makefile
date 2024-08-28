CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	so_long.c get_next_line.c get_next_line_utils.c\
		create_matrix.c continue_creating_the_matrix.c\
		check_required.c utils.c utils2.c check_required1.c\
		so_long1.c utils3.c so_long2.c so_long3.c

OBJ = $(SRC:.c=.o)
NAME = so_long

# Directories for libraries
FT_PRINTF_DIR = ft_printf
LIBFT_DIR = lib_ft
MLX_DIR = minilibx-linux  # Directory containing MiniLibX

# Libraries
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_LIB = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

# Adding the libraries to the final link
LIBS = $(FT_PRINTF_LIB) $(LIBFT_LIB) $(MLX_LIB)

all: $(NAME)

$(NAME): $(OBJ) $(FT_PRINTF_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -I includes -I $(MLX_DIR) -c $< -o $@

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
