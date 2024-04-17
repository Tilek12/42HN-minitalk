/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:40:03 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/13 19:06:50 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	const char	*ptr_str;
	char		*dst;
	char		*ptr_dst;
	int			len;
	int			i;

	ptr_str = str;
	len = 0;
	i = 0;
	while (ptr_str[len] != '\0')
		len++;
	dst = malloc(len + 1);
	ptr_dst = dst;
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		ptr_dst[i] = ptr_str[i];
		i++;
	}
	ptr_dst[i] = '\0';
	return (dst);
}
