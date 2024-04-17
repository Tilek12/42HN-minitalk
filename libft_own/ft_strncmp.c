/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:24:51 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/12 20:50:53 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_str1;
	unsigned char	*ptr_str2;

	i = 0;
	ptr_str1 = (unsigned char *)str1;
	ptr_str2 = (unsigned char *)str2;
	while ((i < n) && ((ptr_str1[i] != '\0') || (ptr_str2[i] != '\0')))
	{
		if (ptr_str1[i] != ptr_str2[i])
			return (ptr_str1[i] - ptr_str2[i]);
		if (ptr_str1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
