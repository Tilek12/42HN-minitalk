/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:14:31 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/04/29 13:17:27 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static sig_atomic_t	g_message_receiving;

static void	ft_join_char(char symbol, char **msg, int *msg_len, int *buf)
{
	char	*new_msg;
	int		new_msg_len;

	new_msg_len = *msg_len + 1;
	if (new_msg_len >= *buf)
	{
		*buf = (*buf) + 1024;
		new_msg = malloc(*buf);
		if (!new_msg)
		{
			ft_printf("Memory allocation ERROR\n");
			exit(EXIT_FAILURE);
		}
		ft_memcpy(new_msg, *msg, *msg_len);
		free (*msg);
		*msg = new_msg;
	}
	(*msg)[*msg_len] = symbol;
	(*msg)[new_msg_len] = '\0';
	*msg_len = new_msg_len;
}

static void	symbol_handler(char symbol, char **msg, int *buf, int *pid_client)
{
	static int	msg_len;

	if (*msg == NULL)
	{
		msg_len = 0;
		*buf = 1024;
		*msg = malloc(*buf);
		if (*msg == NULL)
		{
			ft_printf("Memory allocation ERROR\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (symbol == '\0')
	{
		kill(*pid_client, SIGUSR1);
		ft_printf("%s\n", *msg);
		free (*msg);
		*msg = NULL;
		msg_len = 0;
		*pid_client = 0;
		g_message_receiving = 0;
		return ;
	}
	ft_join_char(symbol, msg, &msg_len, buf);
}

static void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit_counter;
	static char	symbol;
	static char	*message;
	static int	buffer;
	static int	pid_client;

	(void)context;
	pid_client = info->si_pid;
	g_message_receiving = 1;
	if (signal == SIGUSR1)
		symbol = (symbol << 1) | 0;
	else if (signal == SIGUSR2)
		symbol = (symbol << 1) | 1;
	else
		return ;
	bit_counter++;
	if (bit_counter == 8)
	{
		symbol_handler(symbol, &message, &buffer, &pid_client);
		bit_counter = 0;
		symbol = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		if (!g_message_receiving)
			pause();
	}
	return (0);
}
