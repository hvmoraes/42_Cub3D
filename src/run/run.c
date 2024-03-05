/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:14:18 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/27 14:14:18 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel(int x, int y, int color)
{
	char	*dst;

	dst = data()->mlx->addr + (y * data()->mlx->ll + x
			* (data()->mlx->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_line(int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;
    int e2;

    while (1)
    {
        put_pixel(x0, y0, color);

        if (x0 == x1 && y0 == y1)
            break;

        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void	put_square(int y, int x, int size, int color)
{
	int end_x;
	int end_y;
	int	i;
	int	j;

	end_x = x * size + size;
	end_y = y * size + size;
	i = y * size;
	while (i < end_y)
	{
		j = x * size;
		while (j < end_x)
		{
			put_pixel(j, i, color);
			j++;
		}
		i++;
	}
}

void	drawRays()
{
	int r, mx, my, mp, dof; float rx, ry, ra, xo, yo;
	ra = data()->player.floatDir;
	for (r = 0; r < 1; r++)
	{
		dof = 0;
		float aTan = -1 / tan(ra);
		if (ra > M_PI)
		{
			ry = (((int)(data()->player.pos.y) >> 6) << 6) - 0.0001;
			rx = (data()->player.pos.y - ry) * aTan + data()->player.pos.x;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra < M_PI)
		{
			ry = (((int)(data()->player.pos.y) >> 6) << 6) + 64;
			rx = (data()->player.pos.y - ry) * aTan + data()->player.pos.x;
			yo = -64;
			xo = -yo * aTan;
		}
		if (ra == 0 || ra == M_PI )
		{
			rx = data()->player.pos.x;
			ry = data()->player.pos.y;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx)>>6; my = (int)(ry)>>6; mp = my * HEIGHT + mx;
			printf("x = %i rx %i y = %i mp = %i\n", mx, (int)rx, my, mp);
			if (my >= 0 && my < 8 && mx >= 0 && mx < 8)
			{
				if (mp < HEIGHT * WIDTH && data()->map[my][mx] == '1')
					dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof += 1;
			}
		}
		draw_line(data()->player.pos.y * 64 + 4, data()->player.pos.x * 64 + 4, rx * 64, ry * 64, RED);
	}
}

void	draw_mini()
{
	int	x;
	int	y;
	int	color;

	color = BLACK;
	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			if (data()->map[y / 8][x / 8] == '1')
				color = WHITE;
			else
				color = BLACK;
			put_square(y, x, HEIGHT / 64, color);
			x++;
		}
		y++;
	}
}

void	draw_player()
{
	//printf("player x = %f y = %f\n", data()->player.pos.x, data()->player.pos.y);
	put_square(data()->player.pos.x * 8, data()->player.pos.y * 8, HEIGHT / 64, YELLOW);
}

int render(void)
{
	draw_mini();
	draw_player();
	drawRays();
	mlx_put_image_to_window(data()->mlx->mlx, data()->mlx->win, data()->mlx->img, 0, 0);
	return (SUCCESS);
}

int	close_window(void)
{
	free_mlx();
	free_all();
	exit(0);
	return (SUCCESS);
}

int	valid_move(int keycode)
{
	if (keycode == 119 && data()->map[(int)(data()->player.pos.x - 0.1)][(int)data()->player.pos.y] != '1')
		return (SUCCESS);
	else if (keycode == 97 && data()->map[(int)data()->player.pos.x][(int)(data()->player.pos.y - 0.1)] != '1')
		return (SUCCESS);
	else if (keycode == 115 && data()->map[(int)(data()->player.pos.x + 0.1)][(int)data()->player.pos.y] != '1')
		return (SUCCESS);
	else if (keycode == 100 && data()->map[(int)data()->player.pos.x][(int)(data()->player.pos.y + 0.1)] != '1')
		return (SUCCESS);
	return (FAILURE);
}

int	key_hooks(int keycode)
{
	printf("Before: floatDir = %f, dir.x = %f, dir.y = %f\n", data()->player.floatDir, data()->player.dir.x, data()->player.dir.y);

	if (keycode == 65307)
		close_window();
	else if (keycode == 119 && !valid_move(keycode))
		data()->player.pos.x -= 0.1;
	else if (keycode == 97 && !valid_move(keycode))
		data()->player.pos.y -= 0.1;
	else if (keycode == 115 && !valid_move(keycode))
		data()->player.pos.x += 0.1;
	else if (keycode == 100 && !valid_move(keycode))
		data()->player.pos.y += 0.1;
	else if (keycode == 65363)
	{
		data()->player.floatDir += 0.1;
		if (data()->player.floatDir > 2 * M_PI)
			data()->player.floatDir -= 2 * M_PI;
		data()->player.dir.x = cos(data()->player.floatDir) * 5;
		data()->player.dir.y = sin(data()->player.floatDir) * 5;
	}
	else if (keycode == 65361)
	{
		data()->player.floatDir -= 0.1;
		if (data()->player.floatDir < 0)
			data()->player.floatDir += 2 * M_PI;
		data()->player.dir.x = cos(data()->player.floatDir) * 5;
		data()->player.dir.y = sin(data()->player.floatDir) * 5;
	}
	printf("After: floatDir = %f, dir.x = %f, dir.y = %f\n", data()->player.floatDir, data()->player.dir.x, data()->player.dir.y);
	//printf("keycode = %i\n", keycode);
	return (SUCCESS);
}

void	run_mlx(void)
{
	mlx_loop_hook(data()->mlx->mlx, render, NULL);
	mlx_key_hook(data()->mlx->win, key_hooks, NULL);
	mlx_hook(data()->mlx->win, 17, 17, close_window, NULL);
	mlx_loop(data()->mlx->mlx);
}

void	run(void)
{
	init_mlx();
	run_mlx();
	//ft_putstr_fd("Congrats! Valid map passed!\n", 1);
}
