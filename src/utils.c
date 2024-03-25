#include "../inc/cub3D.h"

t_var	*vars(void)
{
	static t_var	va;

	return (&va);
}

int	check_images(void)
{
	if (vars()->gra->no.img_ptr && vars()->gra->so.img_ptr && \
	vars()->gra->we.img_ptr && vars()->gra->ea.img_ptr)
		return (1);
	return (0);
}

double	distance(int ax, int ay, int bx, int by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}
