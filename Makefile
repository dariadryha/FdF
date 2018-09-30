NAME = fdf
CFLAGS = -Wall -Werror -Wextra
VFLAGS = -lmlx -framework OpenGL -framework AppKit
CC = gcc
SRCS = 	$(addprefix srcs/, main.c read_data.c extra1.c extra2.c extra3.c draw_map.c \
	matrix_operations.c vector_operations.c init_matrix.c \
	matrix_rotation.c make_gradient.c bresenhams_line.c draw_lines.c\
	matrix_transformation.c)
OBJ = $(SRCS:.c=.o)
HEAD = fdf.h
HEAD_DIR = minilibx_macos
LIB_DIR = libft
LIB = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(VFLAGS) -L $(HEAD_DIR) $^ $(LIB_DIR)/$(LIB) -o $@

%.o:%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIB_DIR)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
