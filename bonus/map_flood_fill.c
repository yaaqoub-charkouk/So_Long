/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_flood_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:03:15 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/04 16:24:09 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static void	flood_fill(char **map, int x, int y, t_flood *f)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x]
		|| map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		f->c_found++;
	if (map[y][x] == 'E')
		f->e_found = 1;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, f);
	flood_fill(map, x - 1, y, f);
	flood_fill(map, x, y + 1, f);
	flood_fill(map, x, y - 1, f);
}

static char	**duplicate_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	copy[height] = NULL;
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]); 
		if (!copy[i])
		{
			ft_free_matrix(copy, i);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

int	validate_map(char **map, t_game *game)
{
	t_flood	flood;
	char	**map_copy;

	flood.c_found = 0;
	flood.e_found = 0;
	map_copy = duplicate_map(map, game->m_height);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, game->p_x, game->p_y, &flood);
	ft_free_matrix(map_copy, game->m_height);
	if (flood.c_found != game->total_collectibles)
	{
		ft_printf("Map error: Not all collectibles are reachable.\n");
		return (0);
	}
	if (!flood.e_found)
	{
		ft_printf("Map error: The exit is not reachable.\n");
		return (0);
	}
	return (1);
}
