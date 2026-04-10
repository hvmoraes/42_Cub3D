/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:00:00 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/04/10 10:00:00 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	draw_minimap_tile(int mx, int my, int color)
{
	int	px;
	int	py;
	int	i;
	int	j;

	px = MINIMAP_PAD + mx * MINIMAP_SCALE;
	py = MINIMAP_PAD + my * MINIMAP_SCALE;
	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			put_pixel(vars()->gra->canvas, px + i, py + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_grid(void)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < vars()->map_height)
	{
		x = 0;
		while (x < vars()->map_width)
		{
			if (vars()->map[y][x] == 1)
				color = MINIMAP_WALL;
			else
				color = MINIMAP_FLOOR;
			draw_minimap_tile(x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap_player(void)
{
	int	px;
	int	py;
	int	i;
	int	j;

	px = MINIMAP_PAD + (int)(vars()->player->x / CUBESIZE) * MINIMAP_SCALE;
	py = MINIMAP_PAD + (int)(vars()->player->y / CUBESIZE) * MINIMAP_SCALE;
	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			put_pixel(vars()->gra->canvas, px + MINIMAP_SCALE
				/ 2 + i, py + MINIMAP_SCALE / 2 + j, MINIMAP_PLAYER);
			j++;
		}
		i++;
	}
}

static void	draw_minimap_dir(void)
{
	int		i;
	double	dx;
	double	dy;
	int		px;
	int		py;

	px = MINIMAP_PAD + (int)(vars()->player->x / CUBESIZE) * MINIMAP_SCALE
		+ MINIMAP_SCALE / 2;
	py = MINIMAP_PAD + (int)(vars()->player->y / CUBESIZE) * MINIMAP_SCALE
		+ MINIMAP_SCALE / 2;
	dx = lut_cos(vars()->player->angle);
	dy = lut_sin(vars()->player->angle);
	i = 0;
	while (i < MINIMAP_SCALE * 3)
	{
		put_pixel(vars()->gra->canvas, px + (int)(dx * i),
			py + (int)(dy * i), MINIMAP_RAY);
		i++;
	}
}

void	draw_minimap(void)
{
	draw_minimap_grid();
	draw_minimap_player();
	draw_minimap_dir();
}
