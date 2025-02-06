/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:55:01 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/03 16:55:22 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	key_handler(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->p_x;
	new_y = game->p_y;
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_game(game);
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
	if (game->p_x != new_x || game->p_y != new_y)
		mov_player(game, new_x, new_y);
	return (0);
}

int	close_handler(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
}
