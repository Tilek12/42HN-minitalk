/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:46:40 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/15 20:29:20 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_striteri
Prototype -		void ft_striteri(char *s, void (*f)(unsigned int,
								char*));
Turn in files -
Parameters -	s: The string on which to iterate.
				f: The function to apply to each character.
Return value -	None
External functs. -	None
Description -	Applies the function ’f’ on each character of
				the string passed as argument, passing its index
				as first argument. Each character is passed by
				address to ’f’ to be modified if necessary.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		(*f)(i, s);
		++s;
		++i;
	}
}
