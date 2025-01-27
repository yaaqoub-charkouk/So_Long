#include "header.h"

int	ft_count_height(char *file)
{
	int height;
	int fd;

	fd = open(file, O_RDONLY); //open
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd); //close
	return (height);
}

static char	**read_map_from_file(char *file)
{
	int		fd;
	char	**map;
	char 	*line;
	int 	height;
	int		i;

	height = ft_count_height(file); // count the height of the map (lines) && do not call it again !
	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		return (ft_printf("Map error: allocation failure !\n"), NULL);
	map[height] = NULL; // null terminator hh
	fd = open(file, O_RDONLY); // we assume that the file is readable and not empty !
	while (i < height)
	{
		map[i] = get_next_line(fd); // getnextline == no leak ,handle the case when strdup return NULL !!
		if (!map[i])
			return (ft_printf("Map error: allocation failure !\n"), ft_free_matrix(map, height), NULL); //free all if failure
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

int    map(char *filename)
{
	int p_x;
	int p_y;
	int collectibles_count;
	char **map;

	if (!check_map_path(filename) || !is_file_exists_empty(filename))
		return (0);
	else
	{
		map = read_map_from_file(filename);
		if (!map)
			return (0);
	}
	if (!is_map_retungular(map) || !is_map_enclosed(map) || !validate_map_chars(map)) // tha map was readable now yeah !
		return (0);
	get_player_and_collectibles(map, &p_x, &p_y, &collectibles_count);
	if (!validate_map(map, ft_count_height(filename), p_x, p_y, collectibles_count))
		return (0);
	return (1);
}
