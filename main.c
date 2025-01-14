#include <mlx.h>
#include "header.h"


void mario_hook(int keycode, t_data *game)
{
    if (keycode == 53)
        exit(0);
    else if (keycode == KEY_UP)
        game->mario_y -= 50;
    else if (keycode == KEY_DOWN)
        game->mario_y += 50;
    else if (keycode == KEY_LEFT)
        game->mario_x -= 50;
    else if (keycode == KEY_RIGHT)
        game->mario_x += 50;
    mlx_clear_window(game->mlx, game->mlx_win);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
    mlx_put_image_to_window(game->mlx, game->mlx_win, game->mario_img, game->mario_x, game->mario_y);
}

int main(void)
{
    t_data game;

    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, 1920, 1080, "Iy Tech");
    game.img = mlx_xpm_file_to_image(game.mlx, "textures/background.xpm", &game.width, &game.height);
    game.addr = mlx_get_data_addr(game.img, &game.bits_per_pixel, &game.line_length, &game.endian);
    game.mario_img = mlx_xpm_file_to_image(game.mlx, "textures/mario_down.xpm", &game.mario_width, &game.mario_height);

    mlx_put_image_to_window(game.mlx, game.mlx_win, game.img, 0, 0);
    game.mario_x = 10;
    game.mario_y = 10;
    mlx_put_image_to_window(game.mlx, game.mlx_win, game.mario_img, game.mario_x, game.mario_y);

    mlx_key_hook(game.mlx_win, mario_hook, &game);//list for signals

    

    mlx_loop(game.mlx);

    return (0);
}