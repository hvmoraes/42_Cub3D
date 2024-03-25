#include "../inc/cub3D.h"

void	hooks(t_win window)
{
	mlx_hook(window.win_ptr, 2, 1L << 0, key_hook, vars());
	mlx_hook(window.win_ptr, 17, 1L << 0, free_all, vars());
	mlx_loop_hook(window.mlx_ptr, render_hook, NULL);
	mlx_loop(window.mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		vars()->dr = ((FOV / (double)(SCREENWIDTH)) * (PI / 180));
		inits(argv[1]);
		hooks(*vars()->win);
		return (0);
	}
	else
		printf("Error\nUsage: ./cub3d something.cub\n");
	return (1);
}
