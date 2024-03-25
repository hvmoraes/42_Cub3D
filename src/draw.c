#include "../inc/cub3D.h"

void	draw(void)
{
	int			y;
	t_pos		pos;
	int			color;
	t_img		wall;

	pos.x = vars()->player->x;
	pos.y = vars()->player->y;
	pos.color = rgb_to_int(0, 255, 0);
	draw_utils();
	wall = wall_image();
	wall_collision();
	y = 0;
	while (y < vars()->line_h)
	{
		color = \
		get_pixel(wall, (int)(vars()->tx) + (int)(vars()->ty) * CUBESIZE);
		pos.x = vars()->rays.ray * vars()->pix_size;
		pos.y = SCREENHEIGHT / 2 - vars()->line_h / 2 + y;
		pos.color = color * vars()->shade;
		draw_floor_ceiling(vars()->pix_size, vars()->pix_size, pos);
		vars()->ty += vars()->ty_step;
		y++;
	}
}

void	rays(void)
{
	double	angle;

	init_rays();
	vars()->rays.ray = 0;
	angle = vars()->rays.angle;
	while (vars()->rays.ray < SCREENWIDTH)
	{
		angle = vars()->rays.angle;
		check_horizontal(angle);
		check_vertical(angle);
		wall_color();
		draw();
		vars()->rays.ray++;
	}
}

void	draw_all(void)
{
	init_player_pos();
	rays();
}
