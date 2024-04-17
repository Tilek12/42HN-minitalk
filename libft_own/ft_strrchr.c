/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:00:24 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/12 18:39:08 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	str_len;

	str_len = 0;
	while (str[str_len] != '\0')
		str_len++;
	if ((char)c == '\0')
		return ((char *)str + str_len);
	while (str_len >= 0)
	{
		if (str[str_len] == (char)c)
			return ((char *)str + str_len);
		str_len--;
	}
	return (NULL);
}
