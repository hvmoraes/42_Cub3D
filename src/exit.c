#include "../inc/cub3D.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	exit_program(int exit_status)
{
	if (vars()->win->mlx_ptr)
	{
		if (vars()->gra->canvas.img_ptr)
			mlx_destroy_image(vars()->win->mlx_ptr, \
			vars()->gra->canvas.img_ptr);
		if (vars()->gra->no.img_ptr)
			mlx_destroy_image(vars()->win->mlx_ptr, vars()->gra->no.img_ptr);
		if (vars()->gra->so.img_ptr)
			mlx_destroy_image(vars()->win->mlx_ptr, vars()->gra->so.img_ptr);
		if (vars()->gra->ea.img_ptr)
			mlx_destroy_image(vars()->win->mlx_ptr, vars()->gra->ea.img_ptr);
		if (vars()->gra->we.img_ptr)
			mlx_destroy_image(vars()->win->mlx_ptr, vars()->gra->we.img_ptr);
		mlx_destroy_window(vars()->win->mlx_ptr, vars()->win->win_ptr);
		mlx_destroy_display(vars()->win->mlx_ptr);
		free(vars()->win->mlx_ptr);
	}
	if (vars()->gra)
		free(vars()->gra);
	exit(exit_status);
}
