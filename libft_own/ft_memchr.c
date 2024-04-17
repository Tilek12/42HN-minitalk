/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:53:14 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/13 10:40:40 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*ptr_str;
	unsigned char		uns_c;
	size_t				len;

	ptr_str = str;
	uns_c = (unsigned char)c;
	len = n;
	while (len != 0)
	{
		if (*ptr_str == uns_c)
			return ((void *)ptr_str);
		ptr_str++;
		len--;
	}
	return (NULL);
}
