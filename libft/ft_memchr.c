/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam <marvin@42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:59:09 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/13 17:42:54 by lud-adam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;

	p_s = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*p_s == (unsigned char)c)
			return ((void *)p_s);
		p_s++;
	}
	return (NULL);
}
