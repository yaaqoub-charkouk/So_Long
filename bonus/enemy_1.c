/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:11:28 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/05 14:11:29 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	count_enemies(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = -1;
	while (++y < game->m_height)
	{
		x = -1;
		while (++x < game->m_width)
			if (game->map[y][x] == 'G')
				count++;
	}
	return (count);
}

void	store_enemy_positions(t_game *game)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = -1;
	while (++y < game->m_height)
	{
		x = -1;
		while (++x < game->m_width)
		{
			if (game->map[y][x] == 'G')
			{
				game->enemies[index].x = x;
				game->enemies[index].y = y;
				index++;
			}
		}
	}
}

void	get_enemy_pos(t_game *game)
{
	game->num_enemies = count_enemies(game);
	game->enemies = malloc(sizeof(t_enemy) * game->num_enemies);
	if (!game->enemies)
		return ;
	store_enemy_positions(game);
}

void	calculate_enemy_move(t_game *game, int *dx, int *dy, int i)
{
	*dx = 0;
	*dy = 0;
	if (game->p_x > game->enemies[i].x)
		*dx = 1;
	else if (game->p_x < game->enemies[i].x)
		*dx = -1;
	if (game->p_y > game->enemies[i].y)
		*dy = 1;
	else if (game->p_y < game->enemies[i].y)
		*dy = -1;
}
