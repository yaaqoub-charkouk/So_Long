/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:47:01 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/09 16:57:12 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	if (len)
	{
		i = 0;
		while (i < len && haystack[i] != '\0')
		{
			j = 0;
			while (j + i < len && haystack[i + j] == needle[j] 
				&& needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
			i++;
		}
	}
	return (NULL);
}
