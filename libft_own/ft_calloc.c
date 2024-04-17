/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:59:00 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/13 18:39:47 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	unsigned char	*p;
	size_t			len;
	size_t			i;

	len = count * size;
	ptr = malloc(len);
	i = 0;
	if (ptr != NULL)
	{
		p = ptr;
		while (i < len)
		{
			p[i] = 0;
			i++;
		}
	}
	return (ptr);
}
