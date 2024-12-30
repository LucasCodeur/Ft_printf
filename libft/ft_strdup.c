/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:56:00 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/17 16:42:01 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(s) + 1;
	dest = malloc(size * sizeof(char));
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s, size);
	return (dest);
}
