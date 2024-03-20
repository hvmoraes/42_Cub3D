#include "../inc/cub3D.h"

t_var	*vars(void)
{
	static t_var	va;

	return (&va);
}

//aux do draw_line
void	line_vars(t_pos pos, int x1, int y1)
{
	(void)pos.color;
	vars()->dx = abs(x1 - pos.x);
	if (pos.x < x1)
		vars()->sx = 1;
	else
		vars()->sx = -1;
	vars()->dy = -abs(y1 - pos.y);
	if (pos.y < y1)
		vars()->sy = 1;
	else
		vars()->sy = -1;
	vars()->err = vars()->dx + vars()->dy;
}

double	distance(int ax, int ay, int bx, int by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	handle_hooks_and_put_image(t_win window)
{
	mlx_hook(window.win_ptr, 2, 1L << 0, key_hook, vars());
	mlx_hook(window.win_ptr, 17, 1L << 0, exit_program, vars());
	mlx_loop_hook(window.mlx_ptr, (void *) render_hook, NULL);
	mlx_loop(window.mlx_ptr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		vars()->dr = ((FOV / (double)(SCREENWIDTH)) * (PI / 180));
		initialize_game(argv[1]);
		return (0);
	}
	else
		printf("Error\nUsage: ./cub3d something.cub\n");
	return (1);
}
