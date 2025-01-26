/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 07:40:52 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/07 12:16:22 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	str = malloc((end - start + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}
