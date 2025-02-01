#include "header.h"

int key_handler(int keycode, t_game *game)
{
	int new_x;
	int new_y;
	char next_tile;

	new_x = game->p_x;
	new_y = game->p_y;

	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_RIGHT)
		new_x++;
	else if (keycode == KEY_LEFT)
		new_x--;

	// if (game->map[new_y][new_x] != '1') // If not a wall, move the player
	// {
	// 	game->p_x = new_x;
	// 	game->p_y = new_y;
	// 	mlx_clear_window(game->mlx, game->win); // Clear the window
	// 	draw_map(game); // Redraw the game with the updated position
	// }
	next_tile = game->map[new_y][new_x];
	if (next_tile != '1') // If not a wall
	{
        if (next_tile == 'C') // Collectible found
        {
            game->map[new_y][new_x] = '0'; // Remove collectible
            game->collected_items++; // Track collected items
        }

        if (next_tile == 'E' && game->collected_items == game->total_collectibles) // Exit condition
        {
            ft_printf("Congratulations! You won!\n");
            free_game(game);
            exit(0);
        }
        game->p_x = new_x;
        game->p_y = new_y;
        game->moves++; // Count moves
        ft_printf("Moves: %d\n", game->moves);
    }

	// Call the drawmap function here to draw the new image
	// draw_map(game);

	return 0;
}

int	close_handler(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}