/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:40:34 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/04/20 10:00:21 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(int pid, char c)
{
	int	bit_array[8];
	int	i;

	i = 0;
	while (i < 8)
	{
		bit_array[7 - i] = (c >> i) & 1;
		i++;
	}
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
	int		pid_server;
	char	*message;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Follow this rule: %s <pid> <message>", argv[0]);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	while (message[i])
	{
		send_message(pid_server, message[i]);
		i++;
	}
	if (message[i] == '\0')
		send_message(pid_server, '\0');
	return (0);
}
