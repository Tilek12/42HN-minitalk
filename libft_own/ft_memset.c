/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:49:44 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/11 16:11:22 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = str;
	i = 0;
	while (i < len)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (str);
}
