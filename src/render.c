#include "header.h"

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->background_img, 0, 0); // put the background first
	while (y < game->m_height)
	{
		x = 0;
		while (x < game->m_width)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall, x * T_SIZE, y * T_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collectibles, x * T_SIZE, y * T_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x * T_SIZE, y * T_SIZE);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->p_img, x * T_SIZE, y * T_SIZE);
			x++;
		}
		y++;
	}
}
