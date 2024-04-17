/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:57:15 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/04/08 14:15:39 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = count * size;
	ptr = malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	if (ptr != NULL)
	{
		while (i < len)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	if ((char)c == '\0')
		return ((char *)str + i);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

size_t	ft_str_len(char *str)
{
	size_t	length;

	if (str == NULL)
		return (0);
	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = ft_str_len(s1);
	len_s2 = ft_str_len(s2);
	i = 0;
	dst = ft_calloc(((len_s1 + len_s2) + 1), sizeof(char));
	if (dst == NULL)
		return (NULL);
	if (s1 == NULL)
		ft_str_copy(dst, s2, len_s2);
	else
	{
		ft_str_copy(dst, s1, len_s1);
		ft_str_copy(dst + len_s1, s2, len_s2);
	}
	return (free (s1), dst);
}

void	ft_str_copy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
