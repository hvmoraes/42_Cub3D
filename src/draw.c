#include "../inc/cub3D.h"

void	draw_3d_aux1(void)
{
	vars()->ca = vars()->player->angle - vars()->rays.angle;
	if (vars()->ca < 0)
		vars()->ca += 2 * PI;
	if (vars()->ca > 2 * PI)
		vars()->ca -= 2 * PI;
	vars()->rays.dist = vars()->rays.dist * cos(vars()->ca);
	vars()->line_h = (CUBESIZE * SCREENHEIGHT / vars()->rays.dist);
	vars()->ty_step = CUBESIZE / vars()->line_h;
	vars()->ty_off = 0;
	if (vars()->line_h > SCREENHEIGHT)
	{
		vars()->ty_off = (vars()->line_h - SCREENHEIGHT) / 2;
		vars()->line_h = SCREENHEIGHT;
	}
	vars()->rays.angle += vars()->dr;
	if (vars()->rays.angle < 0)
		vars()->rays.angle += 2 * PI;
	if (vars()->rays.angle >= 2 * PI)
		vars()->rays.angle -= 2 * PI;
	vars()->ty = vars()->ty_off * vars()->ty_step;
	vars()->shade = 1;
}

void	draw_3d_aux2(void)
{
	if (vars()->rays.dh >= vars()->rays.dv)
	{
		vars()->tx = (int)(vars()->rays.ry) % CUBESIZE;
		vars()->shade = 0.5;
	}
	else
		vars()->tx = (int)(vars()->rays.rx) % CUBESIZE;
	vars()->rays.dh *= cos(vars()->ca);
	vars()->pix_size = 1;
}

t_img	get_wall_img(void)
{
	if (vars()->rays.dh >= vars()->rays.dv)
	{
		if (vars()->rays.rx < vars()->player->x)
			return (vars()->graphics->we);
		return (vars()->graphics->ea);
	}
	else
	{
		if (vars()->rays.ry < vars()->player->y)
			return (vars()->graphics->so);
		return (vars()->graphics->no);
	}
}

void	draw_3d_walls(void)
{
	int			y;
	t_pos		pos;
	int			color;
	t_img		wall;

	pos.x = vars()->player->x;
	pos.y = vars()->player->y;
	pos.color = rgb_to_int(0, 255, 0);
	draw_3d_aux1();
	wall = get_wall_img();
	draw_3d_aux2();
	y = 0;
	while (y < vars()->line_h)
	{
		color = \
		get_pixel_img(wall, (int)(vars()->tx) + (int)(vars()->ty) * CUBESIZE);
		pos.x = vars()->rays.ray * vars()->pix_size;
		pos.y = SCREENHEIGHT / 2 - vars()->line_h / 2 + y;
		pos.color = color * vars()->shade;
		draw_rectagle(vars()->pix_size, vars()->pix_size, pos);
		vars()->ty += vars()->ty_step;
		y++;
	}
}
