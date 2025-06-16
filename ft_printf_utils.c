/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:17:43 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/20 13:51:08 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Convert a number into a specified base and writes 
// the result to standard output
void	putbase(int fd, unsigned long nb, char *base, int *count)
{
	int		tmp;
	size_t	size;

	size = ft_strlen(base);
	if (nb >= size)
		putbase(fd, nb / size, base, count);
	tmp = write(fd, &base[nb % size], 1);
	*count += tmp;
	if (tmp == -1)
	{
		*count = tmp;
		return ;
	}
}

// Write a char
int	print_char(int fd, char c)
{
	return (write(fd, &c, 1));
}

// Write a string
int	print_str(int fd, char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += ft_putstr_fd("(null)", fd);
		return (count);
	}
	count += ft_putstr_fd(str, fd);
	return (count);
}

// Write a number
int	print_nbr(int fd, long nb, char *base)
{
	int		count;
	size_t	size;

	count = 0;
	size = ft_strlen(base);
	if (nb < 0 && size == 10)
	{
		nb = -nb;
		count = write(fd, "-", fd);
		if (count == -1)
			return (-1);
	}
	putbase(fd, nb, base, &count);
	return (count);
}

// Write in a hexadecimal format
int	print_hex(int fd, void *p, char *base)
{
	int	count;

	count = 0;
	if (!p)
	{
		count = ft_putstr_fd("(nil)", fd);
		return (count);
	}
	count = ft_putstr_fd("0x", fd);
	if (count == -1)
		return (-1);
	putbase(fd, (unsigned long)p, base, &count);
	return (count);
}
