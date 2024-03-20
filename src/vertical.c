#include "../inc/cub3D.h"

void	vertical_vars(double ra)
{
	vars()->rays.dof = 0;
	vars()->rays.dv = 1000000;
	vars()->rays.vx = vars()->player->x;
	vars()->rays.vy = vars()->player->y;
	vars()->rays.ntan = -tan(ra);
}

void	vertical_loop(void)
{
	double	dv;

	vars()->rays.mx = (int)(vars()->rays.rx) >> 6;
	vars()->rays.my = (int)(vars()->rays.ry) >> 6;
	vars()->rays.mp = vars()->rays.my * vars()->map_width + vars()->rays.mx;
	if (vars()->rays.mx < 0 || vars()->rays.my < 0 || \
vars()->rays.mx > vars()->map_width || vars()->rays.my > vars()->map_height)
		vars()->rays.mp = vars()->map_width * vars()->map_height;
	if (vars()->rays.mp > 0 && vars()->rays.mp < vars()->map_width * \
vars()->map_height && vars()->map[vars()->rays.my][vars()->rays.mx] == 1)
	{
		vars()->rays.dof = MAXSIZE;
		vars()->rays.vx = vars()->rays.rx;
		vars()->rays.vy = vars()->rays.ry;
		dv = distance(vars()->player->x, \
vars()->player->y, vars()->rays.vx, vars()->rays.vy);
		vars()->rays.dv = dv;
	}
	else
	{
		vars()->rays.rx += vars()->rays.xo;
		vars()->rays.ry += vars()->rays.yo;
		vars()->rays.dof += 1;
	}
}

void	vertical_check(double ra)
{
	vertical_vars(ra);
	left_or_right(ra);
	up_or_down(ra);
	while (vars()->rays.dof < MAXSIZE)
		vertical_loop();
}
