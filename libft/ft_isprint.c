/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam <marvin@42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:17:16 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/06 15:25:11 by lud-adam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

static int	ft_isponctuation(int c)
{
	if ((c >= '!' && c <= '/') || (c >= '[' && c <= '`') || (c >= '{'
			&& c <= '~') || (c >= ':' && c <= '@'))
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (ft_isalnum(c) == 1 || ft_space(c) == 1 || ft_isponctuation(c) == 1)
		return (1);
	return (0);
}
