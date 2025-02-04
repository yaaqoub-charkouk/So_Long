/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:02:46 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/04 16:23:33 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	load_player_textures(t_game *game)
{
	game->p_r_img = mlx_xpm_file_to_image(game->mlx, "textures/player_right.xpm", &game->p_width, &game->p_height);
	game->p_l_img = mlx_xpm_file_to_image(game->mlx, "textures/player_left.xpm", &game->p_width, &game->p_height);
	game->p_u_img = mlx_xpm_file_to_image(game->mlx, "textures/player_up.xpm", &game->p_width, &game->p_height);
	game->p_d_img = mlx_xpm_file_to_image(game->mlx, "textures/player_down.xpm", &game->p_width, &game->p_height);
	if (!game->p_r_img || !game->p_l_img || !game->p_u_img || !game->p_d_img)
	{
		return (ft_printf("Error: Failed to load Player textures\n"), 0);
	}
	return (1);
}

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("Error: MLX init failed\n"), 0);
	game->win = mlx_new_window(game->mlx,
			game->m_width * T_SIZE, game->m_height * T_SIZE, "IY TECH");

	game->wall = mlx_xpm_file_to_image(game->mlx,
									   "textures/wall.xpm", &game->w_width, &game->w_height);
	game->collectibles = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm", &game->c_width, &game->c_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &game->e_width, &game->e_height);
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"textures/ghost.xpm", &game->p_width, &game->p_height);
	if (!load_player_textures(game))
		return (0);
	game->moves = 0;
	if (!game->win || !game->wall || !game->enemy
		|| !game->collectibles || !game->exit_img)
		return (ft_printf("Init error: failed to init game \n"),
			free_game(game), 0);
	return (1);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		ft_free_matrix(game->map, game->m_height);
}
