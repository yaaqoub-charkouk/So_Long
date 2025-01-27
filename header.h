// #include <mlx.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	void	*mario_img;
	int		mario_x;
	int		mario_y;
	int 	mario_width;
	int 	mario_height;
} t_data;

typedef struct	s_count
{
	int e_count;
	int c_count;
	int p_count;
} t_count


#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124

int		check_map_path(char *str);
int		is_map_retungular(char **map);
int		is_map_enclosed(char **map);
int 	validate_map_chars(char **map);
char	**read_map_from_file(char *file);
int		validate_map(char **map, int map_height, int player_x, int player_y, int collectibles_count);
int		ft_count_height(char *file);