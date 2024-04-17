/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:55:46 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/27 01:23:20 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char fs, va_list arg)
{
	int	char_counter;

	char_counter = 0;
	if (fs == 'c')
		char_counter += ft_print_char(va_arg(arg, int));
	else if (fs == 's')
		char_counter = ft_print_str(va_arg(arg, char *));
	else if (fs == 'p')
		char_counter = ft_print_ptr_adr(va_arg(arg, void *));
	else if ((fs == 'd') || (fs == 'i'))
		char_counter = ft_print_digit((long)va_arg(arg, int));
	else if (fs == 'u')
		char_counter = ft_print_dig_uns((long)va_arg(arg, unsigned int));
	else if ((fs == 'x') || (fs == 'X'))
		char_counter = ft_print_hexadec((long)va_arg(arg, unsigned int), fs);
	else if (fs == '%')
		char_counter = ft_print_char('%');
	else
		char_counter = ft_print_char(fs);
	if (char_counter == (-1))
		return (-1);
	return (char_counter);
}
