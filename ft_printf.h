/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:08:57 by lud-adam          #+#    #+#             */
/*   Updated: 2024/12/20 11:50:09 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# ifndef BASE_HEX
#  define BASE_HEX "0123456789abcdef"
# endif

# ifndef BASE_HEX_MAJ
#  define BASE_HEX_MAJ "0123456789ABCDEF"
# endif

size_t	ft_strlen(const char *str);
int		ft_putstr_fd(char *s, int fd);
int		print_hex(int fd, void *p, char *base);
int		print_char(int fd, char c);
int		print_str(int fd, char *str);
int		print_nbr(int fd, long nb, char *base);
int		ft_printf(int fd, const char *format, ...);

#endif
