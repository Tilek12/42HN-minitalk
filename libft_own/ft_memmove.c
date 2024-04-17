/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:09:30 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/12 10:24:37 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*copy_data_forward(char *d, const char *s, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

static void	*copy_data_backward(char *d, const char *s, size_t l)
{
	size_t	i;

	i = l;
	while (i > 0)
	{
		d[i - 1] = s[i - 1];
		i--;
	}
	return (d);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ptr_dst;
	const char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	if ((ptr_dst == NULL) && (ptr_src == NULL))
		return (NULL);
	else
	{
		if ((ptr_src < ptr_dst) && ((ptr_src + len) > ptr_dst))
			copy_data_backward(ptr_dst, ptr_src, len);
		else if ((ptr_src > ptr_dst) && ((ptr_dst + len) > ptr_src))
			copy_data_forward(ptr_dst, ptr_src, len);
		else
			copy_data_forward(ptr_dst, ptr_src, len);
		return (dst);
	}
}
