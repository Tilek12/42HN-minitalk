/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:10:10 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/04/18 19:09:10 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig)
{
	static int	bit_counter;
	static char	message;

	bit_counter = 0;
	message = 0;
	ft_printf("Received signal: %d\n", sig);
	if (sig == SIGUSR1)
		message = (message << 1) | 0;
	else if (sig == SIGUSR2)
		message = (message << 1) | 1;
	else
		return ;
	ft_printf("message before char: %d\n", message);
	bit_counter++;
	if (bit_counter == 8)
	{
		ft_printf("message inside char: %d\n", message);
		ft_printf("%c", message);
		bit_counter = 0;
		message = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	struct sigaction	sa;
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
