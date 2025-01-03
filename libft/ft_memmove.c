/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam <marvin@42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:42:43 by eveil             #+#    #+#             */
/*   Updated: 2024/11/26 10:30:01 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;

	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (!p_src)
		return (NULL);
	if (p_dest <= p_src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			p_dest[n - 1] = p_src[n - 1];
			n--;
		}
	}
	return (dest);
}
