#include "header.h"
// basic checks of map
int	check_map_path(char *str) // 0 = false
{
	char **split;
	int i;

	i = 0;
	if (ft_strchr(str, '/') < 0)
		return (0);
	split = ft_split(str, '/');
	while (split[i++]) // check the len of basename .ber
	if (i != 3)
		return (0); // check if 
	if (ft_strlen(split[i - 1]) < 4)
		return (ft_free_matrix(split, i), 0);// free the splited string
	return (1);
}

int	is_file_exists_empty(char *filename) // 0 = false
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1) // check if the file does not exist
	{
		perror("Error: Map file does not exist or cannot be opened");
		return (0);
	}
	if (!get_next_line(fd)) //check if the file readeable and not empty
		return (ft_printf("Error: File %s is empty.\n", filename), close(fd), 0);
	close(fd);
	return (1);
}

int	is_map_retungular(char **map) // need to read the map
{
	int	len;
	int i;

	i = 0;
	len = ft_strlen(map[i]); // the len of the first line
	while (map[i])
	{
		if (ft_strlen(map[i]) != len) // check if lines are equal
			return (ft_printf("Error: Map is not rectangular.\n"), 0);
		i++;
	}
	if (i == len ) //check if height > width
			return (ft_printf("Error: Map height is greater than width.\n"), 0);
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
	len = ft_strlen(map[0]) - 1;
	i = 0;
	while (i <= len)
	{
		if (map[0][i] != '1' || map[height][i] != '1') //lfoq o ltaht
			return (ft_printf("Error: Map is not enclosed by walls"), 0);
		i++;
	}
	i = 0;
	while (i <= height)
	{
		if (map[i][0] != '1' || map[i][len]!= '1') // right and left
			return (ft_printf("Error: Map is not enclosed by walls"), 0);
		i++;
	}
	return (1);
}

