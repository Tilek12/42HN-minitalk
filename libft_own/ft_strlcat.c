/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:39:57 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/18 21:25:04 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	len_dst;
	size_t	space;
	size_t	len_src;

	i = 0;
	len_dst = 0;
	len_src = ft_strlen(src);
	while (dst[len_dst] && len_dst < len)
		len_dst++;
	space = len - len_dst;
	if ((space == 0) || (src[i] == '\0'))
		return (len_dst + len_src);
	while (src[i] && (i + 1 < space))
	{
		dst[len_dst + i] = src [i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
