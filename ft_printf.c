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

#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}

// Allow to handle differents format of printf
static int	print_format(int fd, char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count = print_char(fd,va_arg(args, int));
	else if (format == 's')
		count = print_str(fd, va_arg(args, char *));
	else if (format == 'p')
		count = print_hex(fd, va_arg(args, void *), BASE_HEX);
	else if (format == 'd')
		count = print_nbr(fd, va_arg(args, int), BASE_HEX);
	else if (format == 'u')
		count = print_nbr(fd,va_arg(args, unsigned int), BASE_HEX);
	else if (format == 'i')
		count = print_nbr(fd, va_arg(args, int), BASE_HEX);
	else if (format == 'x')
		count = print_nbr(fd, va_arg(args, unsigned int), BASE_HEX);
	else if (format == 'X')
		count = print_nbr(fd, va_arg(args, unsigned int), BASE_HEX_MAJ);
	else if (format == '%')
		count = write(fd, "%", 1);
	return (count);
}

// Write to the standard output
int	ft_printf_fd(int fd, const char *format, ...)
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
			count += print_format(fd, *++format, args);
		else
			count += write(fd, format, 1);
		if (count == -1)
			return (-1);
		++format;
	}
	va_end(args);
	return (count);
}
