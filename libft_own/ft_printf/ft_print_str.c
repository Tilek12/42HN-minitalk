/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:32:46 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/27 01:32:27 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	char_counter;
	int	i;
	int	ret_value;

	char_counter = 0;
	i = 0;
	if (str == NULL)
	{
		if (write (1, "(null)", 6) == (-1))
			return (-1);
		return (6);
	}
	while (str[i] != '\0')
	{
		ret_value = ft_print_char(str[i]);
		if (ret_value == -1)
			return (-1);
		char_counter += ret_value;
		i++;
	}
	return (char_counter);
}
