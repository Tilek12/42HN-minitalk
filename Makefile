# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 16:41:38 by tkubanyc          #+#    #+#              #
#    Updated: 2024/04/16 18:51:48 by tkubanyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft

SERVER_SRC = server.c
CLIENT_SRC = client.c
LIBFT_SRC = $(LIBFT_DIR)/libft.a
PRINTF_SRC = $(LIBFT_DIR)/ft_printf/libftprintf.a
GNL_SRC = $(LIBFT_DIR)/ft_get_next_line/get_next_line.c \
			$(LIBFT_DIR)/ft_get_next_line/get_next_line_utils.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

all: server client

server: $(SERVER_OBJ) $(GNL_OBJ)
	$(MAKE) -C $(LIBFT_DIR)/ft_printf
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(GNL_OBJ) $(LIBFT_SRC) $(PRINTF_SRC) -o server

client: $(CLIENT_OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(GNL_OBJ) $(LIBFT_SRC) $(PRINTF_SRC) -o client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR)/ft_printf clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(GNL_OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR)/ft_printf fclean
	rm -f server client

re: fclean all

.PHONY: all clean fclean re
