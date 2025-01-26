#include "header.h"

int	check_map_path(char *str)
{
	char **split;

	if (ft_strchr(str, '/') < 0)
	{
		return (0);
	}
	split = ft_split(str, '/');
	if (ft_strlen(split[2]) < 4)
		return (0);
	
}

int	main(int ac, char **av)
{
	//check if the av is valid file
	if (ac != 2)
	{
		ft_printf("invalid input : %s <map_path.ber> ", av[0]);
		return (1);
	}
	check_map_path(av[1]);

}