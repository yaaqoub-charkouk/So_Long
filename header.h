#include </Users/ycharkou/mlx.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct	s_game {
	void	*mlx;
	void	*win;
	// background
	void	*background_img; // at init_game
	int		b_width; 
	int		b_height;
	// walls
	void	*wall; // at init_game
	int		w_width;
	int		w_height;
	//exit
	void	*exit_img; // at init_game
	int		e_width;
	int		e_height;
	//collectibles
	void	*collectibles; // at init_game
	int		c_width;
	int		c_height;
	int		collected_items; // map_main_parse
	int		total_collectibles; // map_main_parse
	// player
	void	*p_img; // player
	int		p_x; // from pam_main_read.c
	int		p_y; // from pam_main_read.c
	int 	p_width; // at init_game
	int 	p_height; // at init_game
	//map
	char	**map; // from map_main_read.c
	int		m_width; // from map_check_1.c
	int		m_height; // from map_main_read.c
	//moves
	int		moves; // at init_game
} t_game; // main structure

typedef struct	s_count
{
	int e_count;
	int c_count;
	int p_count;
} t_count;

typedef struct s_flood
{
	int	c_found;
	int	e_found;
}	t_flood;

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define ESC 53
# define T_SIZE 64

int		check_map_path(char *str);
int 	is_map_retungular(char **map, t_game *game);
int 	is_map_enclosed(char **map);
int 	validate_map_chars(char **map);
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