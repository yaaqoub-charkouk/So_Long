/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:10:55 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/09 17:13:01 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	size_t	i;

	source = (char *)src;
	dest = (char *)dst;
	i = 0;
	if (dest > source)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	else if (dest < source)
	{
		while (len--)
			*dest++ = *source++;
	}
	return (dst);
}
