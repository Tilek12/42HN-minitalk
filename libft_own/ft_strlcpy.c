/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:51:20 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/13 12:06:14 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len_dst)
{
	const char	*ptr_src;
	char		*ptr_dst;
	size_t		len_src;
	size_t		i;

	ptr_src = src;
	ptr_dst = dst;
	len_src = 0;
	i = 0;
	while (ptr_src[len_src] != '\0')
		len_src++;
	if ((dst == NULL) || (dst == NULL))
		return (0);
	if (len_dst == 0)
		return (len_src);
	while ((i < len_dst - 1) && (ptr_src[i] != '\0'))
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	ptr_dst[i] = '\0';
	return (len_src);
}
