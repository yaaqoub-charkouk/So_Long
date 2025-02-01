/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:11:56 by ycharkou          #+#    #+#             */
/*   Updated: 2025/01/30 18:05:23 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strchr(const char *accumulation, int c)
{
	ssize_t	i;

	i = 0;
	if (!accumulation)
		return (-1);
	while (accumulation[i])
	{
		if (accumulation[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static size_t	ft_strlen(const char *accumulation)
{
	size_t	i;

	i = 0;
	if (!accumulation)
		return (0);
	while (accumulation[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *acc, char *buff)
{
	char	*string;
	size_t	i;
	size_t	j;

	string = malloc((ft_strlen(acc) + ft_strlen(buff) + 1) * sizeof(char));
	if (!string)
		return (free(acc), NULL);
	i = 0;
	if (acc)
	{
		while (acc[i])
		{
			string[i] = acc[i];
			i++;
		}
	}
	j = 0;
	while (buff[j])
	{
		string[i + j] = buff[j];
		j++;
	}
	return (free(acc), string[i + j] = '\0', string);
}

char	*ft_strdup(const char *s1)
{
	char	*string;
	size_t	i;

	i = 0;
	string = malloc(ft_strlen(s1) + 1 * sizeof(char));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	return (string[i] = '\0', string);
}

char	*ft_substr(char *accumulation, unsigned int start, size_t len)
{
	char	*sub;
	size_t	final;
	size_t	i;

	if (!accumulation)
		return (NULL);
	final = ft_strlen(accumulation) - start;
	if (final > len)
		final = len;
	sub = malloc((final + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < final && accumulation[start + i])
	{
		sub[i] = accumulation[start + i];
		i++;
	}
	return (sub[i] = '\0', sub);
}
