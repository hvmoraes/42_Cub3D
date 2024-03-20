#include "../inc/cub3D.h"

void	horizontal_vars(double ra)
{
	vars()->rays.dof = 0;
	vars()->rays.dh = 1000000;
	vars()->rays.hx = vars()->player->x,
	vars()->rays.hy = vars()->player->y;
	vars()->rays.atan = -1 / tan(ra);
}

void	horizontal_aux(void)
{
	vars()->rays.mx = (int)(vars()->rays.rx) >> 6;
	vars()->rays.my = (int)(vars()->rays.ry) >> 6;
	vars()->rays.mp = vars()->rays.my * vars()->map_width + vars()->rays.mx;
	if (vars()->rays.mx < 0 || vars()->rays.my < 0 \
	|| vars()->rays.mx > vars()->map_width
		|| vars()->rays.my > vars()->map_height)
		vars()->rays.mp = vars()->map_width * vars()->map_height;
}

void	horizontal_loop(void)
{
	double	dh;

	horizontal_aux();
	if (vars()->rays.mp > 0 && vars()->rays.mp < vars()->map_width \
		* vars()->map_height \
		&& vars()->map[vars()->rays.my][vars()->rays.mx] == 1)
	{
		vars()->rays.hx = vars()->rays.rx;
		vars()->rays.hy = vars()->rays.ry;
		dh = distance(vars()->player->x, vars()->player->y, \
		vars()->rays.hx, vars()->rays.hy);
		vars()->rays.dh = dh;
		vars()->rays.dof = 8;
	}
	else
	{
		vars()->rays.rx += vars()->rays.xo;
		vars()->rays.ry += vars()->rays.yo;
		vars()->rays.dof += 1;
	}
}

void	horizontal_check(double ra)
{
	horizontal_vars(ra);
	look_up_or_down(ra);
	look_left_or_right(ra);
	while (vars()->rays.dof < 8)
		horizontal_loop();
}

void	img_teste(t_img *img, char *line)
{
	if (img->img_ptr)
		mlx_destroy_image(vars()->win->mlx_ptr, img->img_ptr);
	img->img_ptr = mlx_xpm_file_to_image(vars()->win->mlx_ptr, \
		line + 3, &img->w, &img->h);
	if (!img->img_ptr)
	{
		free(line);
		exit_program(printf("Error\nInvalid texture provided\n"));
		return ;
	}
	img->addr = mlx_get_data_addr(img->img_ptr, \
	&img->bpp, &img->line_len, &img->endian);
}
