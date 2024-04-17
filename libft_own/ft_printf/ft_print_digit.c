/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:59:47 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/27 01:17:16 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_base_10(int num)
{
	int	counter;
	int	ret_value_1;
	int	ret_value_2;

	if (num < 10)
	{
		ret_value_1 = ft_print_char((num % 10) + '0');
		if (ret_value_1 == (-1))
			return (-1);
		return (ret_value_1);
	}
	else
	{
		ret_value_1 = ft_print_base_10(num / 10);
		if (ret_value_1 == (-1))
			return (-1);
		ret_value_2 = ft_print_base_10(num % 10);
		if (ret_value_2 == (-1))
			return (-1);
		counter = ret_value_1 + ret_value_2;
		return (counter);
	}
}

int	ft_print_digit(int num)
{
	int	char_counter;
	int	ret_value;

	char_counter = 0;
	if (num == -2147483648)
	{
		if (write(1, "-2147483648", 11) == (-1))
			return (-1);
		return (char_counter = 11);
	}
	else if (num < 0)
	{
		if (write(1, "-", 1) == (-1))
			return (-1);
		ret_value = ft_print_digit(-num);
		if (ret_value == (-1))
			return (-1);
		char_counter = ret_value + 1;
		return (char_counter);
	}
	char_counter = ft_print_base_10(num);
	if (char_counter == (-1))
		return (-1);
	return (char_counter);
}
