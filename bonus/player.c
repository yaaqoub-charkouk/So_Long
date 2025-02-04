/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:58:58 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/04 17:29:04 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

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
		if (next_tile == 'E' 
			&& game->collected_items == game->total_collectibles)
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
	draw_map(game);
}

void	put_player_image(t_game *game)
{
	if (game->p_direction == 'u')
		mlx_put_image_to_window(game->mlx,
			game->win, game->p_u_img, game->p_x * T_SIZE, game->p_y * T_SIZE);
	else if (game->p_direction == 'd')
		mlx_put_image_to_window(game->mlx,
			game->win, game->p_d_img, game->p_x * T_SIZE, game->p_y * T_SIZE);
	else if (game->p_direction == 'l')
		mlx_put_image_to_window(game->mlx,
			game->win, game->p_l_img, game->p_x * T_SIZE, game->p_y * T_SIZE);
	else if (game->p_direction == 'r')
		mlx_put_image_to_window(game->mlx,
			game->win, game->p_r_img, game->p_x * T_SIZE, game->p_y * T_SIZE);
}
