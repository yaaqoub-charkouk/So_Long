/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:11:37 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/05 16:48:41 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	apply_enemy_move(t_game *game, int i, int dx, int dy)
{
	int	new_x;
	int	new_y;
	int	old_x;
	int	old_y;

	old_x = game->enemies[i].x;
	old_y = game->enemies[i].y;
	new_x = game->enemies[i].x + dx;
	new_y = game->enemies[i].y + dy;
	if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'C' && game->map[new_y][new_x] != 'E') 
	{
		game->map[old_y][old_x] = '0';
		game->enemies[i].x = new_x;
		game->enemies[i].y = new_y;
		game->map[new_y][new_x] = 'G';
		if (game->enemies[i].x == game->p_x && game->enemies[i].y == game->p_y)
			exit_failure(game);
	}
}

void	move_enemies(t_game *game)
{
	int	i;
	int	dx;
	int	dy;

	i = 0;
	while (i < game->num_enemies)
	{
		calculate_enemy_move(game, &dx, &dy, i);
		apply_enemy_move(game, i, dx, dy);
		i++;
	}
}

void	draw_enemy(t_game *game, int i)
{
	mlx_put_image_to_window(game->mlx, game->win, game->enemy,
		game->enemies[i].x * T_SIZE, game->enemies[i].y * T_SIZE);
}

void	put_enemy_image(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->num_enemies)
	{
		draw_enemy(game, i);
		i++;
	}
}

int	enemy_loop(t_game *game)
{
	move_enemies(game);
	draw_map(game);
	return (0);
}
