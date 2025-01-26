/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:13:16 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/04 13:35:10 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*v;
	size_t			i;

	v = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		v[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
