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

void	putbase(unsigned long nb, char *base, unsigned long size, int *count)
{
	int	tmp;

	tmp = 0;
	if (nb >= size)
		putbase(nb / size, base, size, count);
	tmp += write(1, &base[nb % size], 1);
	*count += tmp;
	if (tmp == -1)
	{
		*count = tmp;
		return ;
	}
}

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int		count;

	count = 0;
	if (!str)
	{
		count += ft_putstr_fd("(null)", 1);
		if (count == -1)
			return (-1);
		return (6);
	}
	count += ft_putstr_fd(str, 1);
	return (count);
}

int	print_nbr(long nb, char *base, long size)
{
	int	count;

	count = 0;
	if (nb < 0 && size == 10)
	{
		nb = -nb;
		count += write(1, "-", 1);
		if (count == -1)
			return (-1);
	}
	putbase(nb, base, size, &count);
	return (count);
}

int	print_hex(void *p, char *base, long size)
{
	int		count;

	count = 0;
	if (!p)
	{
		count = ft_putstr_fd("(nil)", 1);
		if (count == -1)
			return (-1);
		return (5);
	}
	count += ft_putstr_fd("0x", 1);
	if (count == -1)
		return (-1);
	putbase((unsigned long)p, base, size, &count);
	return (count);
}

// int	main(void)
// {
// 	int	count;
// 	char	*str;
//
// 	count = 0;
// 	str = NULL; 
// 	// count = ft_printf("Salut\n");
// 	// printf("%d\n", count);
//
// 	// count = ft_printf("%d\n", 42);
// 	// printf("%d\n", count);
//
// 	// count = ft_printf("%d\n", 2147483647);
// 	// printf("%d\n", count);
//
// 	// count = ft_printf("%d\n", -2147483648);
// 	// printf("%d\n", count);
//
// 	// count = ft_printf(0);
// 	// printf("%d\n", count);
//
// 	// count = ft_printf("%p", count);
// 	// printf("%d\n", count);
//
// 	// count = ft_printf("%s", str);
// 	// printf("%d\n", count);
//
// 	count = ft_printf("%d", 42);
// 	printf("%d\n", count);
//
// 	return (0);
// }
