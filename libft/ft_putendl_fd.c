/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:48:56 by lud-adam          #+#    #+#             */
/*   Updated: 2024/11/20 19:50:30 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	count += write(fd, s, ft_strlen(s));
	count += write(fd, "\n", 1);
	return (count);
}
