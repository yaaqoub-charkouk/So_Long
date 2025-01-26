/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:16:19 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/09 17:13:17 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*source;
	unsigned char		*dest;

	if (dst == src)
		return (dst);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	i = 0;
	while (n > 0)
	{
		*dest = *source;
		dest++;
		source++;
		n--;
	}
	return (dst);
}
