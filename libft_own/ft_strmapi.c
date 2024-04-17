/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 20:32:57 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/15 20:51:21 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_strmapi
Prototype -		char *ft_strmapi(char const *s, char (*f)(unsigned
								int, char));
Turn in files -
Parameters -	s: The string on which to iterate.
				f: The function to apply to each character.
Return value -	The string created from the successive applications
				of ’f’.
				Returns NULL if the allocation fails.
External functs. -	malloc
Description -	Applies the function ’f’ to each character of the
				string ’s’, and passing its index as first argument
				to create a new string (with malloc(3)) resulting
				from successive applications of ’f’.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len_s;
	unsigned int	i;
	char			*dst;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	dst = malloc(len_s + 1);
	if (dst == NULL)
		return (NULL);
	while (s[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[len_s] = '\0';
	return (dst);
}
