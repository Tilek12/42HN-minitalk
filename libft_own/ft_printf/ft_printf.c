/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:43:08 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/27 01:29:11 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		char_counter;
	va_list	arg;
	int		error_check;

	va_start(arg, format);
	char_counter = 0;
	error_check = 0;
	while (*format)
	{
		if (*format == '%')
			error_check = ft_print_format(*(++format), arg);
		else
			error_check = ft_print_char(*format);
		if (error_check == (-1))
			return (-1);
		char_counter += error_check;
		error_check = 0;
		format++;
	}
	va_end(arg);
	return (char_counter);
}
