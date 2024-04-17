/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:11:45 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/13 12:57:09 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*ptr_str1;
	const unsigned char	*ptr_str2;
	size_t				i;

	ptr_str1 = str1;
	ptr_str2 = str2;
	i = 0;
	while (i < n)
	{
		if (ptr_str1[i] != ptr_str2[i])
			return (ptr_str1[i] - ptr_str2[i]);
		i++;
	}
	return (0);
}
