# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 16:41:38 by tkubanyc          #+#    #+#              #
#    Updated: 2024/04/19 15:36:24 by tkubanyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror

SERVER_SRC 	= server.c
CLIENT_SRC 	= client.c
LIBFT_SRC 	= libft_own/libft.a
PRINTF_SRC 	= libft_own/ft_printf/libftprintf.a
GNL_SRC 	= libft_own/ft_get_next_line/get_next_line.c \
				libft_own/ft_get_next_line/get_next_line_utils.c \

SERVER_BONUS_SRC = server_bonus.c
CLIENT_BONUS_SRC = client_bonus.c

SERVER_OBJ 	= $(SERVER_SRC:.c=.o)
CLIENT_OBJ 	= $(CLIENT_SRC:.c=.o)
GNL_OBJ 	= $(GNL_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

all: server client

server: $(SERVER_OBJ) $(GNL_OBJ)
	$(MAKE) -C libft_own/ft_printf
	$(MAKE) -C libft_own
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(GNL_OBJ) $(LIBFT_SRC) $(PRINTF_SRC) -o server

client: $(CLIENT_OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(GNL_OBJ) $(LIBFT_SRC) $(PRINTF_SRC) -o client

bonus: $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ) $(GNL_OBJ)
	$(MAKE) -C libft_own/ft_printf
	$(MAKE) -C libft_own
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(GNL_OBJ) $(LIBFT_SRC) $(PRINTF_SRC) -o server_bonus
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(GNL_OBJ) $(LIBFT_SRC) $(PRINTF_SRC) -o client_bonus
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft_own/ft_printf clean
	$(MAKE) -C libft_own clean
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(GNL_OBJ) $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)

fclean: clean
	$(MAKE) -C libft_own/ft_printf fclean
	$(MAKE) -C libft_own fclean
	rm -f server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re bonus
