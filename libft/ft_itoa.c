/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:55:06 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/20 15:54:37 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	compute_size(int n)
{
	long	temp;
	int		size;

	size = 0;
	temp = (long)n;
	if (n == 0)
		return (size + 1);
	if (n < 0)
	{
		temp = -temp;
		size++;
	}
	while (temp > 0)
	{
		temp /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	long	temp;
	char	*dest;

	temp = (long)n;
	size = compute_size(temp);
	dest = ft_calloc(size + 1, sizeof(char));
	if (!dest)
		return (dest);
	i = size - 1;
	dest[size] = '\0';
	if (n < 0)
	{
		temp = -temp;
		dest[0] = '-';
		size--;
	}
	while (size-- > 0)
	{
		dest[i] = (temp % 10) + 48;
		temp /= 10;
		i--;
	}
	return (dest);
}
