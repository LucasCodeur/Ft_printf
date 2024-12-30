/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:01:58 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/20 13:41:13 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	**ft_free(char **strs, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j + 1)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*ft_strdupp(const char *s, char c, size_t *i)
{
	char	*dest;
	size_t	len;
	size_t	j;

	len = 0;
	j = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		len++;
		(*i)++;
	}
	dest = ft_calloc(len + 1, sizeof(char));
	if (!dest)
		return (dest);
	*i -= len;
	while (s[*i] != c && s[*i] != '\0')
	{
		dest[j] = s[*i];
		(*i)++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**final_array;
	size_t	size;
	size_t	i;
	size_t	j;

	size = count_words(s, c);
	i = 0;
	j = 0;
	final_array = ft_calloc(size + 1, sizeof(char *));
	if (!final_array)
		return (final_array);
	while (j < size)
	{
		while (s[i] == c)
			i++;
		final_array[j] = ft_strdupp(s, c, &i);
		if (!final_array[j])
			return (ft_free(final_array, j));
		while (s[i] == c && s[i] != '\0')
			i++;
		j++;
	}
	return (final_array);
}
