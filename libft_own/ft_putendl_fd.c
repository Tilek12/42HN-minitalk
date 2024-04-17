/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:40:35 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/15 12:49:54 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_putendl_fd
Prototype -		void ft_putendl_fd(char *s, int fd);
Turn in files -
Parameters -	s: The string to output.
				fd: The file descriptor on which to write.
Return value -	None
External functs. -	write
Description -	Outputs the string ’s’ to the given file descriptor
				followed by a newline.
*/

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != 0)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	write(fd, "\n", 1);
}
