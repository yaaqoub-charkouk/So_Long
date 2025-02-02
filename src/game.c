/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:02:46 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/02 19:29:47 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("Error: MLX init failed\n"), 0);
	game->win = mlx_new_window(game->mlx,
			game->m_width * T_SIZE, game->m_height * T_SIZE, "IY TECH");
	game->background_img = mlx_xpm_file_to_image(game->mlx,
			"../textures/background.xpm", &game->b_width, &game->b_height);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"../textures/wall.xpm", &game->w_width, &game->w_height);
	game->p_img = mlx_xpm_file_to_image(game->mlx,
			"../textures/player.xpm", &game->p_width, &game->p_height);
	game->collectibles = mlx_xpm_file_to_image(game->mlx,
			"../textures/collect.xpm", &game->c_width, &game->c_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"../textures/exit.xpm", &game->e_width, &game->e_height);
	// if (!game->win || !game->p_img || !game->background_img
	// 	|| !game->wall || !game->collectibles || !game->exit_img)
	// 	return (ft_printf("Init error: failed to init game \n"),
	// 		free_game(game), 0);
	if (!game->win) {
    ft_printf("Error: game->win is NULL\n");
	}
	if (!game->p_img) {
		ft_printf("Error: game->p_img is NULL\n");
	}
	if (!game->background_img) {
		ft_printf("Error: game->background_img is NULL\n");
	}
	if (!game->wall) {
		ft_printf("Error: game->wall is NULL\n");
	}
	if (!game->collectibles) {
		ft_printf("Error: game->collectibles is NULL\n");
	}
	if (!game->exit_img) {
		ft_printf("Error: game->exit_img is NULL\n");
	}
	
	// init_vars(game); // initialize counters 
	return (1);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	// if (game->p_img)
	// 	mlx_destroy_image(game->mlx, game->p_img);
	// if (game->background_img)
	// 	mlx_destroy_image(game->mlx, game->background_img);
	// if (game->wall)
	// 	mlx_destroy_image(game->mlx, game->wall);
	// if (game->collectibles)
	// 	mlx_destroy_image(game->mlx, game->collectibles);
	// if (game->exit_img)
	// 	mlx_destroy_image(game->mlx, game->exit_img);
	if (game->map)
		ft_free_matrix(game->map, game->m_height);
	// if (game->win)
	// 	mlx_destroy_window(game->mlx, game->win);
	// if (game->mlx)
	// 	free(game->mlx); 
	// exit(0);
}
