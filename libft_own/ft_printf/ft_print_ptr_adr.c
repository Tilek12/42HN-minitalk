/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_adr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:07:31 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/27 01:16:36 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_base_16(unsigned long num)
{
	int		counter;
	char	*hex;
	int		ret_value_1;
	int		ret_value_2;

	hex = "0123456789abcdef";
	if (num < 16)
	{
		ret_value_1 = ft_print_char(hex[num]);
		if (ret_value_1 == (-1))
			return (-1);
		return (ret_value_1);
	}
	else
	{
		ret_value_1 = ft_print_base_16(num / 16);
		if (ret_value_1 == (-1))
			return (-1);
		ret_value_2 = ft_print_base_16(num % 16);
		if (ret_value_2 == (-1))
			return (-1);
		counter = ret_value_1 + ret_value_2;
		return (counter);
	}
}

int	ft_print_ptr_adr(void *ptr)
{
	int				char_counter;
	unsigned long	ptr_value;
	int				ret_value;

	char_counter = 0;
	if (ptr == NULL)
	{
		if (write(1, "0x0", 3) == (-1))
			return (-1);
		return (3);
	}
	ptr_value = (unsigned long)ptr;
	if (write(1, "0x", 2) == (-1))
		return (-1);
	char_counter = 2;
	ret_value = ft_print_base_16(ptr_value);
	if (ret_value == (-1))
		return (-1);
	char_counter += ret_value;
	return (char_counter);
}
