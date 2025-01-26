/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:12:25 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/09 20:34:16 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count(size_t *count, int n)
{
	long int	nb;

	*count = 0;
	if (n == 0)
		*count = 1;
	nb = n;
	if (nb < 0)
	{
		(*count)++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		(*count)++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t		count;
	char		str[12];
	long int	nb;

	ft_count(&count, n);
	nb = n;
	if (n == 0)
		str[0] = '0';
	else if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	str[count--] = '\0';
	while (nb > 0)
	{
		str[count--] = (nb % 10) + '0';
		nb /= 10;
	}
	ft_putstr_fd(str, fd);
}
