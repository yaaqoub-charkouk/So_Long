/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:21:20 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/05 12:53:13 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_map_path(char *filename)
{
	char	**split;
	int		i;

	if (ft_strchr(filename, '/') < 0) 
	{
		if (ft_strlen(filename) < 4 || ft_strncmp(filename 
				+ ft_strlen(filename) - 4, ".ber", 4) != 0)
			return (ft_printf("Map error: invalid path "), 0);
		return (1);
	}
	split = ft_split(filename, '/');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	if (i < 2 || ft_strlen(split[i - 1]) < 4 || ft_strncmp(split[i - 1] 
			+ ft_strlen(split[i - 1]) - 4, ".ber", 4) != 0)
	{
		ft_free_matrix(split, i);
		return (ft_printf("Map error: invalid path "), 0);
	}
	ft_free_matrix(split, i);
	return (1);
}

int	is_map_retungular(char **map, t_game *game)
{
	int	i;

	i = 0;
	game->m_width = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != game->m_width)
			return (ft_printf("Map error: lines are not equal.\n"), 0);
		i++;
	}
	if (i == game->m_width)
		return (ft_printf("Map error: Map height is equal to width.\n"), 0);
	return (1);
}

int	is_map_enclosed(char **map)
{
	int	i;
	int	len;
	int	height;

	height = 0;
	while (map[height])
		height++;
	height--;
	len = ft_strlen(map[0]) - 1;
	i = 0;
	while (i <= len)
	{
		if (map[height][i] != '1' || map[0][i] != '1')
			return (ft_printf("Map error: Map is not enclosed T, B\n"), 0);
		i++;
	}
	i = 0;
	while (i <= height)
	{
		if (map[i][0] != '1' || map[i][len] != '1')
			return (ft_printf("Map error: Map is not enclosed R, L\n"), 0);
		i++;
	}
	return (1);
}
