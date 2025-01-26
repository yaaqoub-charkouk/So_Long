#include <mlx.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"


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

#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124


