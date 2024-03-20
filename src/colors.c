#include "../inc/cub3D.h"

void	color_limits(int *red, int *green, int *blue)
{
	if (*red > 255)
		*red = 255;
	if (*green > 255)
		*green = 255;
	if (*blue > 255)
		*blue = 255;
	if (*red < 0)
		*red = 0;
	if (*green < 0)
		*green = 0;
	if (*blue < 0)
		*blue = 0;
}

int	rgb_to_int(int red, int green, int blue)
{
	color_limits(&red, &green, &blue);
	return (red << 16 | green << 8 | green << 8 | blue);
}

void	wall_color(void)
{
	int	color;

	color = rgb_to_int((int)0, 0, 0);
	if (vars()->rays.dv <= vars()->rays.dh)
	{
		vars()->rays.rx = vars()->rays.vx;
		vars()->rays.ry = vars()->rays.vy;
		vars()->rays.dist = vars()->rays.dv;
		color = rgb_to_int((int)255, 0, 0);
	}
	if (vars()->rays.dv > vars()->rays.dh)
	{
		vars()->rays.rx = vars()->rays.hx;
		vars()->rays.ry = vars()->rays.hy;
		vars()->rays.dist = vars()->rays.dh;
		color = rgb_to_int((int)100, 0, 0);
	}
	vars()->wall_collor = color;
}

void	init_colors(void)
{
	t_color	*color;

	color = &(vars()->color);
	color->r = 0;
	color->g = 0;
	color->b = 0;
}
