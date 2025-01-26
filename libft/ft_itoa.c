/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:44:28 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/09 21:39:00 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_alloc(size_t *count, int n)
{
	long int	nb;

	if (n == 0)
	{
		*count = 1;
		return (malloc(2 * sizeof(char)));
	}
	*count = 0;
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
	return (malloc(((*count) + 1) * sizeof(char)));
}

static char	*ft_asign_str(char	*str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		count;
	char		*str;
	long int	nb;

	str = (char *)ft_alloc(&count, n);
	if (!str)
		return (NULL);
	nb = n;
	if (n == 0)
		return (ft_asign_str(str));
	if (nb < 0)
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
	return (str);
}
