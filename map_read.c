#include "header.h"

int	ft_count_height(char *filename)
{
	int height;
	int fd;

	fd = open(filename, O_RDONLY); //open
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd); //close
	return (height);
}

char	**read_map_from_file(char *filename)
{
	int		fd;
	char	**map;
	char 	*line;
	int 	height;
	int		i;

	height = ft_count_height(filename); // count the height of the map (lines)

	map = malloc(height * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY); // we assume that the file is readable and not empty !
	while (i < height)
	{
		line = get_next_line(fd);
		map[i] = ft_strdup(line); // handle the case when strdup return NULL !!
		if (!map[i])
			return (NULL)

	}




}