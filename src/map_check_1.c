#include "../header.h"
// basic checks of map
int	check_map_path(char *filename) // 0 = false
{
	char **split;
	int i;

	i = 0;
	if (!filename || ft_strchr(filename, '/') < 0) // handle the case when the map in current directory
		return (0);
	split = ft_split(filename, '/');
	if (!split)
		return (0);
	while (split[i++]) // check the len of basename .ber
		if (i != 3)
			return (ft_free_matrix(split, i), 0); // check if , avoid leak 
	if (ft_strlen(split[i - 1]) < 4
			|| ft_strncmp(split[i - 1] + ft_strlen(split[i - 1]) - 4, ".ber", 4) != 0)
		return (ft_free_matrix(split, i), 0);// free the splited string
	ft_free_matrix(split, i); // avoid leak
	return (1);
}

int	is_file_exists_empty(char *filename) // 0 = false
{
	char	*line;
	int 	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1) // check if the file does not exist
	{
		perror("Error: Map file does not exist or cannot be opened\n");
		return (0);
	}
	line = get_next_line(fd);
	if (!line) // check if the file readeable and not empty
		return (ft_printf("Error: File %s is empty.\n", filename), close(fd), 0);
	free(line); // to avoid leak
	close(fd);
	return (1);
}

int	is_map_retungular(char **map, t_game *game) // need to read the map
{
	int i;

	i = 0;
	game->m_width = ft_strlen(map[0]); // the len of the first line == m_width
	while (map[i])
	{
		if (ft_strlen(map[i]) != game->m_width) // check if lines are equal
			return (ft_printf("Error: Map is not rectangular (lines are not equal).\n"), 0);
		i++;
	}
	if (i == game->m_width ) //check if height != width
			return (ft_printf("Error: Map height is equal to width.\n"), 0);
	return (1);
}

int	is_map_enclosed(char **map) // check if the map is enclosed by walls 1
{
	int i;
	int len;
	int height;

	height = 0;
	while (map[height])
		height++;
	height--;
	len = ft_strlen(map[0]) - 2;
	i = 0;
	while (i <= len && map[i])
	{
		// ft_printf("%c\n", map[height][i]);
		if (map[0][i] != '1' || map[height][i] != '1') //lfoq o ltaht
			return (ft_printf("Error: Map is not enclosed by walls (Top or Bottom)\n"), 0);
		i++;
	}
	i = 0;
	while (i <= height)
	{
		// ft_printf("%c\n", map[i][len]);
		if (map[i][0] != '1' || map[i][len] != '1') // right and left
			return (ft_printf("Error: Map is not enclosed by walls (Right or Left)\n"), 0);
		i++;
	}
	return (1);
}

