/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:52:50 by neves             #+#    #+#             */
/*   Updated: 2024/03/25 14:52:51 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw_utils(void)
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

void	wall_collision(void)
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

t_img	wall_image(void)
{
	if (vars()->rays.dh >= vars()->rays.dv)
	{
		if (vars()->rays.rx < vars()->player->x)
			return (vars()->gra->we);
		return (vars()->gra->ea);
	}
	else
	{
		if (vars()->rays.ry < vars()->player->y)
			return (vars()->gra->so);
		return (vars()->gra->no);
	}
}

void	draw_floor_ceiling(int width, int height, t_pos pos)
{
	int	i;
	int	j;

	i = pos.x;
	while (i < pos.x + width)
	{
		j = pos.y;
		while (j < pos.y + height)
		{
			put_pixel(vars()->gra->canvas, i, j, pos.color);
			j++;
		}
		i++;
	}
}
