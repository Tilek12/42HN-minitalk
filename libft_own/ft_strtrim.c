/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:39:09 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/15 10:23:55 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_strtrim
Prototype -		char *ft_strtrim(char const *s1, char const *set);
Turn in files -
Parameters -	s1: The string to be trimmed.
				set: The reference set of characters to trim.
Return value -	The trimmed string.
				NULL if the allocation fails.
External functs. -	malloc
Description -	Allocates (with malloc(3)) and returns a copy of
				’s1’ with the characters specified in ’set’ removed
				from the beginning and the end of the string.
*/

static int	check_c(char const *str, char c)
{
	int	i;
	int	len_str;

	i = 0;
	len_str = ft_strlen(str);
	while (i < len_str)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*copy_str(char *d, char const *s, int st, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		d[i] = s[st + i];
		i++;
	}
	return (d);
}

static char	*empty_dst(void)
{
	char	*str;

	str = malloc(1);
	if (str == NULL)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		len_dst;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1) - 1;
	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	while (s1[start] && check_c(set, s1[start]))
		start++;
	while ((end >= 0) && check_c(set, s1[end]))
		end--;
	if (end < start)
		return (empty_dst());
	len_dst = end - start + 1;
	dst = malloc(len_dst + 1);
	if (dst == NULL)
		return (NULL);
	copy_str(dst, s1, start, len_dst);
	dst[len_dst] = '\0';
	return (dst);
}
