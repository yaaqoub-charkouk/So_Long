#include "header.h"

int key_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == KEY_UP)
		game->p_y--;
	else if (keycode == KEY_DOWN)
		game->p_y++;
	else if (keycode == KEY_RIGHT)
		game->p_x++;
	else if (keycode == KEY_LEFT)
		game->p_x--;

	mlx_clear_window(game->mlx, game->win); // Clear the window

	// Call the drawmap function here to draw the new image
	draw_map(game);

	return 0;
}

int	close_handler(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}