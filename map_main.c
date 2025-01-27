#include "header.h"

int    map(char *filename, int x, int y, int collectibles_count)
{
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
	if (!validate_map(map, ft_count_height(filename), x, y, collectibles_count))
		return (0);
	return (1);
}