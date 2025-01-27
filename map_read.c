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

char	**read_map_from_file(char *file)
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
		map[i] = get_next_line(fd); // getnextline == no leakhandle the case when strdup return NULL !!
		if (!map[i])
			return (ft_printf("Map error: allocation failure !\n"), ft_free_matrix(map, height), NULL); //free all if failure
		i++;
	}
	return (map);
}
