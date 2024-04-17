/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 10:54:35 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/18 17:31:29 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Function name -	ft_itoa
Prototype -		char *ft_itoa(int n);
Turn in files -
Parameters -	n: the integer to convert.
Return value -	The string representing the integer.
				NULL if the allocation fails.
External functs. -	malloc
Description -	Allocates (with malloc(3)) and returns a string
				representing the integer received as an argument.
				Negative numbers must be handled.
*/

static char	*if_int_min_or_zero(int number)
{
	char	*s;

	if (number == -2147483648)
	{
		s = (char *)malloc(sizeof(char) * 12);
		if (s == NULL)
			return (NULL);
		return (ft_memcpy(s, "-2147483648", 12));
	}
	if (number == 0)
	{
		s = (char *)malloc(sizeof(char) * 2);
		if (s == NULL)
			return (NULL);
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	return (NULL);
}

static int	count_i(int digit)
{
	int	temp;
	int	counter;

	temp = digit;
	counter = 0;
	while (temp != 0)
	{
		temp /= 10;
		counter++;
	}
	return (counter);
}

static char	*fill_str(char *s, int digit, int j, int len)
{
	j = len - 2;
	while (digit != 0)
	{
		s[j--] = (digit % 10) + '0';
		digit /= 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;
	int		len_str;

	sign = 1;
	if ((n == 0) || (n == -2147483648))
		return (str = if_int_min_or_zero(n));
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	i = count_i(n);
	len_str = i + 1;
	if (sign == -1)
		len_str++;
	str = (char *)malloc(sizeof(char) * len_str);
	if (!str)
		return (NULL);
	if (sign == -1)
		str[0] = '-';
	str[len_str - 1] = '\0';
	i = len_str - 2;
	return (str = fill_str(str, n, i, len_str));
}
