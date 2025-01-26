/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:01:02 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/08 17:53:25 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	final;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return ((char *)ft_calloc(1, sizeof(char)));
	final = slen - start;
	if (final > len)
		final = len;
	sub = malloc((final + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (char *)(s + start), final + 1);
	return (sub);
}
