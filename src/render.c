/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:35:38 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/02 18:08:07 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	get_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->m_height)
	{
		x = 0;
		while (x < game->m_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	put_image_to_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx,
			game->win, game->wall, x * T_SIZE, y * T_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx,
			game->win, game->collectibles, x * T_SIZE, y * T_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->win, game->exit_img, x * T_SIZE, y * T_SIZE);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	mlx_put_image_to_window(game->mlx,
		game->win, game->background_img, 0, 0);
	mlx_put_image_to_window(game->mlx,
		game->win, game->p_img, game->p_x * T_SIZE, game->p_y * T_SIZE);
	while (y < game->m_height)
	{
		x = 0;
		while (x < game->m_width)
		{
			put_image_to_window(game, x, y);
			x++;
		}
		y++;
	}
}
