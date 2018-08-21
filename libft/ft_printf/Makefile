#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddryha <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:57:14 by ddryha            #+#    #+#              #
#    Updated: 2018/01/12 12:57:14 by ddryha           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = ft_printf.o ft_wputchar.o ft_wchar_len.o ft_wputstr.o ft_wstr_len.o ft_check_type.o \
	ft_itoa_base.o ft_nbr_char.o ft_check_flags.o ft_manage_flags.o ft_print_result.o \
	ft_un_nbr_char.o ft_un_itoa_base.o ft_print_spec_format.o ft_print_wstr.o ft_print_str.o \
	ft_mng_flg_char.o ft_print_char.o ft_hex.o ft_sign_integer.o ft_un_flags.o \
	ft_manage_un_flags.o ft_manage_unsign_length.o ft_manage_sign_length.o ft_print_wchar.o \
	ft_print_percent_result.o ft_print_char_result.o ft_wstr_n_len.o ft_un_sign_data.o

all: $(addprefix ../obj/,$(OBJ))

../obj/%.o : %.c
	@$(CC) -c $(CFLAGS) $< -I ../includes -o $@

clean:
	@rm -rf $(addprefix ../obj/, $(OBJ))

fclean: clean

re: fclean all

.PHONY: all clean fclean re
