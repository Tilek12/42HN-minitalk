/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:49:02 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/11 20:43:15 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;
	size_t		i;

	ptr_dst = dst;
	ptr_src = src;
	i = 0;
	if ((ptr_dst == NULL) && (ptr_src == NULL))
		return (NULL);
	else
	{
		while (i < len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
		return (dst);
	}
}
