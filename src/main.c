/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:59:12 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/03 16:59:43 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("invalid input : %s <map_path.ber> ", av[0]);
		return (1);
	}
	game.map = map_main_parse(av[1], &game);
	if (!game.map)
		return (free_game(&game), 1);
	if (!init_game(&game))
		return (free_game(&game), 1);
	draw_map(&game);
	mlx_key_hook(game.win, key_handler, &game);
	mlx_hook(game.win, 17, 0, close_handler, &game);
	mlx_loop(game.mlx);
	return (free_game(&game), 0);
}
