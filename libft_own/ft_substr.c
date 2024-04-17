/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:35:13 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/14 09:50:51 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name - ft_substr
Prototype - char *ft_substr(char const *s, unsigned int start,
							size_t len);
Parameters - s: The string from which to create the substring.
			start: The start index of the substring in the
			string ’s’.
			len: The maximum length of the substring.
Return value - The substring.
			NULL if the allocation fails.
External functs. - malloc
Description - Allocates (with malloc(3)) and returns a substring
			from the string ’s’.
			The substring begins at index ’start’ and is of
			maximum size ’len’.
*/
static size_t	len_str(char const *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

static size_t	check_len(size_t l_s, unsigned int st, size_t l)
{
	if (l > (l_s - st))
		return (l_s - st);
	else
		return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		len_s;
	size_t		i;

	len_s = len_str(s);
	i = 0;
	if (start >= len_s)
	{
		dst = malloc(1);
		if (dst == NULL)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	len = check_len(len_s, start, len);
	dst = malloc(len + 1);
	if (dst == NULL)
		return (NULL);
	while ((i < len) && (s[start + i] != '\0'))
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
