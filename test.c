#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	square(t_data	*img)
{
	int x;
	int y;

	x = 300;
	y = 300;

	while (y <= 600)
	{
		my_mlx_pixel_put(img, x, y, 0xFFFFFF);
		while (x <= 600)
		{
			my_mlx_pixel_put(img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x = 0;
	int y = 0;
	int color = 0xFFFF0F; // green
	int width = 64;

	mlx = mlx_init(); // initialize , end establish a connection to the correct graphical system .
	mlx_win = mlx_new_window(mlx, 1920, 1080, "iy technology");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	square(&img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);

	return (0);
}