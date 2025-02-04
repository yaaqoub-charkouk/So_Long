#include "../header.h"

void	mov_player(t_game *game, int new_x, int new_y)
{
	char	next_tile;

	next_tile = game->map[new_y][new_x];
	if (next_tile != '1')
	{
		if (next_tile == 'C')
		{
			game->map[new_y][new_x] = '0';
			game->collected_items++;
		}

		if (next_tile == 'E' && game->collected_items == game->total_collectibles)
		{
			ft_printf("Congratulations! You won!\n");
			draw_map(game);
			free_game(game);
			exit(EXIT_SUCCESS);
		}
		game->p_x = new_x;
		game->p_y = new_y;
		game->moves++;
		mlx_clear_window(game->mlx, game->win);
		draw_map(game);
		ft_printf("Moves: %d\n", game->moves);
	}
}
