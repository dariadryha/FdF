#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddryha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 14:46:53 by ddryha            #+#    #+#              #
#    Updated: 2018/01/09 14:46:55 by ddryha           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = ./libft
OBJ = obj/*.o

all: $(NAME)

$(NAME): objdir
	@make -C $(LIBDIR)
	@make -C ft_printf
	@ar rc $(NAME) $(OBJ)

objdir:
	@mkdir -p obj

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm -rf obj

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
