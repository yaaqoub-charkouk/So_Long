#include "../header.h"

size_t	ft_count_height(char *file)
{
	size_t height;
	int fd;
	char *line;

	fd = open(file, O_RDONLY); // open
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line); // free the allocated memory by get_next_line
		line = get_next_line(fd);
	}
	free(line);
	close(fd); // close
	return (height);
}


char	**read_map_from_file(char *file, t_game *game) // ::stored the map height to the struct
{
	int		fd;
	char	**map;
	char 	*line;
	int		i;

	game->m_height = ft_count_height(file); // count the height of the map (lines) && do not call it again !
	// printf("%zu\n", game->m_height); // remove it
	if (!game->m_height)
		return (NULL);
	map = malloc((game->m_height + 1) * sizeof(char *));
	if (!map)
		return (ft_printf("Map error: allocation failure !\n"), NULL); // allocation failure
	map[game->m_height] = NULL; // null terminator hh
	fd = open(file, O_RDONLY); // we assume that the file is readable and not empty !
	i = 0;
	while (i < game->m_height)
	{
		map[i] = get_next_line(fd); // getnextline == no leak ,handle the case when strdup return NULL !!
		// ft_printf("%s", map[i]);
		if (!map[i] && i < (game->m_height - 1))
			return (ft_printf("Map error: allocation failure !\n"), ft_free_matrix(map, game->m_height), NULL); //free all if failure
		i++;
	}
	return (map);
}

static void	get_player_and_collectibles(char **map, int *p_x, int *p_y, int *collectibles_count)
{// this function is to get primary data
	int i;
	int j;

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
	int collectibles_count;
	char **map;

	// if (!check_map_path(filename) || !is_file_exists_empty(filename))
	// 	return (NULL);
	// else
	// {
		map = read_map_from_file(filename, game);
		if (!map)
			return (NULL);
	// }
	if (!is_map_retungular(map, game) || !is_map_enclosed(map) || !validate_map_chars(map)) // tha map was readable now yeah !
		return (NULL);
	get_player_and_collectibles(map, &(game->p_x), &(game->p_y), &collectibles_count);
	if (!validate_map(map, game->m_height, game->p_x, game->p_y, collectibles_count))
		return (NULL);
	return (map); // need to free the map later !!!!!!!!!!!!!! leak
}




int main(int ac, char **av)
{
	t_game game;
	char **map;

	map = map_main_parse(av[1], &game);
	// for (int i = 0; map[i] != NULL; i++) {
	// 	printf("%s\n", map[i]);
	// }

	return 0;
}