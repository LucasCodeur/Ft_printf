/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:30:18 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/19 17:48:31 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strndup(const char *s, size_t len)
{
	char	*dest;
	size_t	size;
	size_t	i;

	size = ft_strlen(s) + 1;
	i = 0;
	if (len >= size)
		dest = ft_calloc(size, sizeof(char));
	else
		dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i] && i < len)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (s[0] == '\0' || start >= (unsigned int)ft_strlen(s) || len == 0)
	{
		dest = malloc(1);
		if (!dest)
			return (dest);
		dest[0] = '\0';
		return (dest);
	}
	dest = ft_strndup(&s[start], len);
	return (dest);
}
