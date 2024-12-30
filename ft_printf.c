/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:07:01 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/19 14:07:59 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char format, va_list args)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(args, int));
	else if (format == 's')
		count += print_str(va_arg(args, char *));
	else if (format == 'p')
		count += print_hex(va_arg(args, void *), "0123456789abcdef", 16);
	else if (format == 'd')
		count += print_nbr(va_arg(args, int), "0123456789abcdef", 10);
	else if (format == 'u')
		count += print_nbr(va_arg(args, unsigned int), "0123456789abcdef", 10);
	else if (format == 'i')
		count += print_nbr(va_arg(args, int), "0123456789abcdef", 10);
	else if (format == 'x')
		count += print_nbr(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (format == 'X')
		count += print_nbr(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (format == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	if (format == 0)
		return (-1);
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, args);
		else
			count += write(1, format, 1);
		if (count == -1)
			return (-1);
		++format;
	}
	va_end(args);
	return (count);
}
