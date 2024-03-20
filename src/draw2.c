#include "../inc/cub3D.h"

void	draw_square(t_img img, int size, t_pos pos)
{
	int	i;
	int	j;

	i = pos.x;
	j = pos.y;
	while (i < pos.x + size)
	{
		while (j < pos.y + size)
		{
			put_pixel_img(img, i, j, pos.color);
			j++;
		}
		i++;
	}
}

void	draw_rays_2d(t_win window)
{
	double	angle;

	init_vars();
	vars()->rays.ray = 0;
	angle = vars()->rays.angle;
	while (vars()->rays.ray < SCREENWIDTH)
	{
		angle = vars()->rays.angle;
		horizontal_check(angle);
		vertical_check(angle);
		wall_color();
		draw_3d_walls();
		vars()->rays.ray++;
	}
	(void)window;
}

void	draw_player_and_rays(t_win window)
{
	initialize_player_position();
	draw_rays_2d(window);
}

void	draw_rectagle(int width, int height, t_pos pos)
{
	int	i;
	int	j;

	i = pos.x;
	while (i < pos.x + width)
	{
		j = pos.y;
		while (j < pos.y + height)
		{
			put_pixel_img(vars()->gra->canvas, i, j, pos.color);
			j++;
		}
		i++;
	}
}
