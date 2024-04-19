/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 12:14:09 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/04/19 18:41:46 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message delivered correctly\n");
}

static void	char_to_bit_array(char c, int bit_array[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		bit_array[7 - i] = (c >> i) & 1;
		i++;
	}
}

static void	send_bit_array(int pid, int bit_array[8])
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (bit_array[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int					pid_server;
	int					pid_client;
	char				*message;
	int					bit_array[8];
	int					i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Follow this rule: %s <pid> <message>", argv[0]);
		return (1);
	}
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid_client = getpid();
	ft_printf("Client PID: %d\n", pid_client);
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	while (message[i])
	{
		char_to_bit_array(message[i], bit_array);
		send_bit_array(pid_server, bit_array);
		i++;
	}
	char_to_bit_array('\0', bit_array);
	send_bit_array(pid_server, bit_array);
}
