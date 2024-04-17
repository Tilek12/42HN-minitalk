/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:33:48 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/27 01:12:47 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hex_low(long num)
{
	int		counter;
	char	*hex_low;
	int		ret_value_1;
	int		ret_value_2;

	hex_low = "0123456789abcdef";
	if (num < 16)
	{
		ret_value_1 = ft_print_char(hex_low[num]);
		if (ret_value_1 == (-1))
			return (-1);
		return (ret_value_1);
	}
	else
	{
		ret_value_1 = ft_print_hex_low(num / 16);
		if (ret_value_1 == (-1))
			return (-1);
		ret_value_2 = ft_print_hex_low(num % 16);
		if (ret_value_2 == (-1))
			return (-1);
		counter = ret_value_1 + ret_value_2;
		return (counter);
	}
}

static int	ft_print_hex_upp(long num)
{
	int		counter;
	char	*hex_upp;
	int		ret_value_1;
	int		ret_value_2;

	hex_upp = "0123456789ABCDEF";
	if (num < 16)
	{
		ret_value_1 = ft_print_char(hex_upp[num]);
		if (ret_value_1 == (-1))
			return (-1);
		return (ret_value_1);
	}
	else
	{
		ret_value_1 = ft_print_hex_upp(num / 16);
		if (ret_value_1 == (-1))
			return (-1);
		ret_value_2 = ft_print_hex_upp(num % 16);
		if (ret_value_2 == (-1))
			return (-1);
		counter = ret_value_1 + ret_value_2;
		return (counter);
	}
}

int	ft_print_hexadec(long num, char c)
{
	int	char_counter;

	if (num < 0)
	{
		char_counter = ft_print_digit(-num);
		if (char_counter == (-1))
			return (-1);
		return (char_counter);
	}
	else
	{
		if (c == 'x')
			char_counter = ft_print_hex_low(num);
		else if (c == 'X')
			char_counter = ft_print_hex_upp(num);
		else
			return (-1);
		if (char_counter == (-1))
			return (-1);
		return (char_counter);
	}
}
