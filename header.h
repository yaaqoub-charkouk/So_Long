/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:01:17 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/04 12:03:59 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include </Users/ycharkou/mlx.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*background_img;
	int		b_width; 
	int		b_height;
	void	*wall;
	int		w_width;
	int		w_height;
	void	*exit_img;
	int		e_width;
	int		e_height;
	void	*collectibles;
	int		c_width;
	int		c_height;
	int		collected_items;
	int		total_collectibles;
	void	*p_img;
	int		p_x;
	int		p_y;
	int		p_width;
	int		p_height;
	char	**map;
	int		m_width;
	int		m_height;
	int		moves;
}	t_game;

typedef struct s_count
{
	int	e_count;
	int	c_count;
	int	p_count;
}	t_count;

typedef struct s_flood
{
	int	c_found;
	int	e_found;
}	t_flood;

#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define ESC 53
#define T_SIZE 64

int		check_map_path(char *str);
int		is_map_retungular(char **map, t_game *game);
int		is_map_enclosed(char **map);
int		validate_map_chars(char **map);
char	**read_map_from_file(char *file, t_game *game);
int		validate_map(char **map, t_game *game);
int		is_file_empty_and_height_count(char *file);
char	**map_main_parse(char *filename, t_game *game);
char	**read_map_from_file(char *file, t_game *game);
int		init_game(t_game *game);
void	draw_map(t_game *game);
int		key_handler(int keycode, t_game *game);
int		close_handler(t_game *game);
void	free_game(t_game *game);
void	mov_player(t_game *game, int new_x, int new_y);