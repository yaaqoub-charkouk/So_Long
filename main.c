#include "header.h"

int	main(int ac, char **av)
{
	//check if the av is valid file
	if (ac != 2)
	{
		ft_printf("invalid input : %s <map_path.ber> ", av[0]);
		return (1);
	}
	if (check_map_path(av[1]) == 0)
	{
		ft_printf("invalid map path !");
		return (1);
	}
}