/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main_and_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:26:36 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/04 16:24:21 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	is_file_empty_and_height_count(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Map file does not exist or cannot be opened\n");
		return (0);
	}
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Map error : file is empty\n"), 0);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (count);
}

char	**read_map_from_file(char *file, t_game *game)
{
	int		fd;
	char	**map;
	int		i;

	game->m_height = is_file_empty_and_height_count(file);
	if (!game->m_height)
		return (NULL);
	map = malloc((game->m_height + 1) * sizeof(char *));
	if (!map)
		return (ft_printf("Map error: allocation failure !\n"), NULL);
	map[game->m_height] = NULL;
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < game->m_height)
	{
		map[i] = get_next_line(fd);
		if (!map[i] && i < (game->m_height - 1))
		{
			ft_printf("Map error: allocation failure !\n");
			return (ft_free_matrix(map, game->m_height), NULL);
		}
		i++;
	}
	close(fd);
	return (map);
}

void	get_p_and_c(char **map, int *p_x, int *p_y, int *collectibles_count)
{
	int	i;
	int	j;

	i = 0;
	*collectibles_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*p_x = j;
				*p_y = i;
			}
			else if (map[i][j] == 'C')
				(*collectibles_count)++;
			j++;
		}
		i++;
	}
}

char	**map_main_parse(char *filename, t_game *game)
{
	char	**map;

	if (!check_map_path(filename))
		return (NULL);
	else
	{
		map = read_map_from_file(filename, game);
		if (!map)
			return (NULL);
	}
	if (!is_map_retungular(map, game)
		|| !is_map_enclosed(map) || !validate_map_chars(map))
		return (ft_free_matrix(map, game->m_height), NULL);
	get_p_and_c(map, &(game->p_x), &(game->p_y), &game->total_collectibles);
	if (!validate_map(map, game))
		return (ft_free_matrix(map, game->m_height), NULL);
	game->collected_items = 0;
	return (map);
}
