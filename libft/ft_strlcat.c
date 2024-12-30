/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam <marvin@42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:06:32 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/12 17:42:42 by lud-adam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_of_dst;
	size_t	size_of_src;
	size_t	i;

	size_of_dst = ft_strlen(dst);
	size_of_src = ft_strlen(src);
	i = 0;
	if (size == 0 || size <= size_of_dst)
		return (size_of_src + size);
	while (src[i] && i < (size - 1) - size_of_dst)
	{
		dst[size_of_dst + i] = src[i];
		i++;
	}
	dst[size_of_dst + i] = '\0';
	return (size_of_src + size_of_dst);
}
