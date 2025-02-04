/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaaqoub <yaaqoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:35:38 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/04 21:59:00 by yaaqoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

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
	else if (game->map[y][x] == 'G')
		mlx_put_image_to_window(game->mlx,
			game->win, game->enemy, x * T_SIZE, y * T_SIZE);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	put_player_image(game);
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
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->win, 70, 10, 0x00FFFFFF, ft_itoa(game->moves));
}
