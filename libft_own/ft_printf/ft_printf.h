/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:40:54 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/03/27 12:36:29 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_print_format(char fs, va_list arg);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_hexadec(long num, char c);
int	ft_print_ptr_adr(void *ptr);
int	ft_print_digit(int num);
int	ft_print_dig_uns(unsigned int num);

#endif
