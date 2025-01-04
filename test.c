#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x = 0;
	int y = 0;
	int color = 0xFFFFFF; // green

	mlx = mlx_init(); // initialize , end establish a connection to the correct graphical system .
	mlx_win = mlx_new_window(mlx, 1920, 1080, "iy technology");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	for (y = 0; y < 1080; y++) {
        for (x = 0; x < 1920; x++) {
            // Calculate the pixel offset in the image
            int offset = (y * img.line_length + x * (img.bits_per_pixel / 8));

            // Set the pixel color in the image data
            *(unsigned int *)(img.addr + offset) = color;
        }
    }

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);

	return (0);
}