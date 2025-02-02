#include "../header.h"

int	main(int ac, char **av)
{
	t_game	game;
	// check if the av is valid file
	if (ac != 2)
	{
		ft_printf("invalid input : %s <map_path.ber> ", av[0]);
		return (1);
	}
	printf("bgjghghgh");
	game.map = map_main_parse(av[1], &game); // need to be freed later !!!!!!! leak
	// also get base info and store them to the struct
	// most of variable in struct are initialized in the function 
	// printf("%c", game.map[0][0]);

	if (!game.map)
		return (free_game(&game), 1);
	
	if (!init_game(&game))
		return (1);
	draw_map(&game);

	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_handler, &game);

	mlx_loop(game.mlx);
	return (0);
}
