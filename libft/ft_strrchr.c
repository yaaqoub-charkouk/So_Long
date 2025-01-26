/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:47:58 by ycharkou          #+#    #+#             */
/*   Updated: 2024/10/29 11:16:36 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		last_index;
	char	ch;

	ch = (char)c;
	last_index = (int)ft_strlen(s);
	if (ch == '\0')
		return ((char *)(s + last_index));
	while (last_index >= 0)
	{
		if (ch == s[last_index])
			return ((char *)(s + last_index));
		last_index--;
	}
	return (NULL);
}
