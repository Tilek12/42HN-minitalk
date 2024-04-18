# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 16:41:38 by tkubanyc          #+#    #+#              #
#    Updated: 2024/04/17 13:33:13 by tkubanyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c
CLIENT_SRC = client.c
LIBFT_SRC = libft_own/libft.a
PRINTF_SRC = libft_own/ft_printf/libftprintf.a
GNL_SRC = libft_own/ft_get_next_line/get_next_line.c \
			libft_own/ft_get_next_line/get_next_line_utils.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

all: server client

server: $(SERVER_OBJ) $(GNL_OBJ)
	$(MAKE) -C libft_own/ft_printf
	$(MAKE) -C libft_own
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(GNL_OBJ) $(LIBFT_SRC) $(PRINTF_SRC) -o server

client: $(CLIENT_OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(GNL_OBJ) $(LIBFT_SRC) $(PRINTF_SRC) -o client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft_own/ft_printf clean
	$(MAKE) -C libft_own clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(GNL_OBJ)

fclean: clean
	$(MAKE) -C libft_own/ft_printf fclean
	$(MAKE) -C libft_own fclean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
