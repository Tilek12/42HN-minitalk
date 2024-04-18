/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:40:34 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/04/18 18:05:28 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_to_bit_array(char c, int bit_array[8])
{
	int i;

	i = 0;
	while (i < 8)
	{
		bit_array[7 - i] = (c >> i) & 1;
		i++;
	}
}

void	send_bit_array(int pid, int bit_array[8])
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
	int		pid;
	char	*message;
	int		bit_array[8];
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Follow this rule: %s <pid> <message>", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (message[i])
	{
		char_to_bit_array(message[i], bit_array);
		send_bit_array(pid, bit_array);
		i++;
	}
	return (0);
}
