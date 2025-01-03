/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:24:37 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/19 17:53:31 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	is_sep(char const c, char const *set)
{
	size_t		i;

	i = 0;
	while (set[i])
	{
		if (c != set[i])
			i++;
		else
			return (1);
	}
	return (0);
}

static size_t	count_without_sep(char const *s1, char const *set)
{
	size_t	size_sep;
	size_t	size_with_sep;
	size_t	index;

	size_sep = 0;
	size_with_sep = ft_strlen(s1);
	index = size_with_sep - 1;
	while (is_sep(s1[size_sep], set) == 1 && s1[size_sep])
		size_sep++;
	if (s1[size_sep] == '\0')
		return (0);
	while (is_sep(s1[index], set) == 1 && s1[index])
	{
		index--;
		size_sep++;
	}
	return (size_with_sep - size_sep);
}

static char	*ft_check_if_size_equal_0(void)
{
	char	*final_array;

	final_array = malloc(1);
	if (!final_array)
		return (final_array);
	final_array[0] = '\0';
	return (final_array);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	size_t	i;
	char	*final_array;

	i = 0;
	size = count_without_sep(s1, set);
	if (size == 0)
	{
		final_array = ft_check_if_size_equal_0();
		return (final_array);
	}
	final_array = ft_calloc(size + 1, sizeof(char));
	if (!final_array)
		return (final_array);
	while (is_sep(s1[i], set) == 1)
		i++;
	ft_memcpy(final_array, &s1[i], size);
	final_array[size] = '\0';
	return (final_array);
}
