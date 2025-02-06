/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:47:30 by ycharkou          #+#    #+#             */
/*   Updated: 2025/01/30 15:42:59 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	bytes_written;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
	i = 0;
	bytes_written = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		bytes_written++;
		i++;
	}
	return (bytes_written);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] == 127)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_nbr(unsigned long nbr, char *base)
{
	int				count;
	int				base_len;

	if (!is_valid_base(base))
		return (0);
	base_len = ft_strlen(base);
	count = 0;
	if (nbr >= (unsigned long)base_len)
		count += ft_nbr(nbr / base_len, base);
	ft_putchar_fd(base[nbr % base_len], 1);
	count++;
	return (count);
}
