/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:37:24 by ycharkou          #+#    #+#             */
/*   Updated: 2024/11/07 12:10:30 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	s_len;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s_len = s1_len + s2_len;
	string = malloc((s_len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, s1_len + 1);
	ft_strlcpy(string + s1_len, s2, s2_len + 1);
	return (string);
}
