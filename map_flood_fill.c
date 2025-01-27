#include "header.h"

// check if all collectibles and the exit are reachable .

// Flood fill function
static void	flood_fill(char **map, int x, int y, int *collectibles_found, int *exit_found)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		(*collectibles_found)++;
	if (map[y][x] == 'E')
		*exit_found = 1;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, collectibles_found, exit_found); // Right
	flood_fill(map, x - 1, y, collectibles_found, exit_found); // Left
	flood_fill(map, x, y + 1, collectibles_found, exit_found); // Down
	flood_fill(map, x, y - 1, collectibles_found, exit_found); // Up
}

// Duplicate a 2D map
static char	**duplicate_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]); //getnextline or libft ??
		if (!copy[i])
		{
			ft_free_matrix(copy, i);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

// Map validation function
int	validate_map(char **map, int map_height, int player_x, int player_y, int collectibles_count)
{
	int		collectibles_found;
	int		exit_found;
	char	**map_copy;

	collectibles_found = 0;
	exit_found = 0;
	map_copy = duplicate_map(map, map_height);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, player_x, player_y, &collectibles_found, &exit_found);
	ft_free_matrix(map_copy, map_height);
	if (collectibles_found != collectibles_count) // check if all collectibles are reachable
	{
		ft_printf("Map error: Not all collectibles are reachable.\n");
		return (0);
	}
	if (!exit_found) //check if the exit is reachable 
	{
		ft_printf("Map error: The exit is not reachable.\n");
		return (0);
	}
	return (1);
}
