/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam <marvin@42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:12:15 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/08 10:48:59 by lud-adam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*p;

	p = (unsigned char *)pointer;
	while (count--)
		*p++ = value;
	return (pointer);
}
