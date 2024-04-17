/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:08:14 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/14 11:35:54 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_strjoin
Prototype - 	char *ft_strjoin(char const *s1, char const *s2);
Turn in files -
Parameters - 	s1: The prefix string.
				s2: The suffix string.
Return value -	The new string.
				NULL if the allocation fails.
External functs. - malloc
Description -	Allocates (with malloc(3)) and returns a new
				string, which is the result of the concatenation
				of ’s1’ and ’s2’.
*/

static size_t	len_str(char const *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	len_s1 = len_str(s1);
	len_s2 = len_str(s2);
	dst = malloc((len_s1 + len_s2) + 1);
	i = 0;
	if ((s1 == NULL) || (s2 == NULL) || (dst == NULL))
		return (NULL);
	while (i < len_s1)
	{
		dst[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		dst[len_s1 + i] = s2[i];
		i++;
	}
	dst[len_s1 + len_s2] = '\0';
	return (dst);
}
