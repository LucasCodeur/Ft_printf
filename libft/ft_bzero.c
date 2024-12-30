/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:46:14 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/23 15:43:05 by eveil            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	value;
	unsigned char	*p;

	value = 0;
	p = (unsigned char *)s;
	while (n >= 2)
	{
		*p++ = value;
		*p++ = value;
		n -= 2;
	}
	if (n-- == 1)
		*p++ = value;
}
