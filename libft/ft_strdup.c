/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:50:44 by ycharkou          #+#    #+#             */
/*   Updated: 2024/10/26 15:50:45 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*string;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1) + 1;
	string = malloc(len * sizeof(char));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
