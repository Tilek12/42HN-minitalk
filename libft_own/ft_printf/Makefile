# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 18:12:15 by tkubanyc          #+#    #+#              #
#    Updated: 2024/03/27 12:37:35 by tkubanyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	ft_print_format.c \
	ft_print_char.c \
	ft_print_str.c \
	ft_print_hexadec.c \
	ft_print_ptr_adr.c \
	ft_print_digit.c \
	ft_print_dig_uns.c \

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
