/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:06:14 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/09 16:35:51 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	size_t			total;

	total = count * size;
	if (!total)
		return (malloc(0));
	if (count != 0 && (total / count) != size)
		return (NULL);
	s = (unsigned char *)malloc(total);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, total);
	return (s);
}
