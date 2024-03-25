/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:52:47 by neves             #+#    #+#             */
/*   Updated: 2024/03/25 14:52:48 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	look_north_south(double ra)
{
	if (ra > PI)
	{
		vars()->rays.ry = (((int)vars()->player->y >> 6) << 6) - 0.0001;
		vars()->rays.yo = -CUBESIZE;
	}
	else
	{
		vars()->rays.ry = (((int)vars()->player->y >> 6) << 6) + CUBESIZE;
		vars()->rays.yo = CUBESIZE;
	}
	vars()->rays.rx = (vars()->player->y - vars()->rays.ry) \
	* vars()->rays.atan + vars()->player->x;
	vars()->rays.xo = -vars()->rays.yo * vars()->rays.atan;
}

void	look_west_east(double ra)
{
	if (ra == 0 || ra == PI)
	{
		vars()->rays.rx = vars()->player->x;
		vars()->rays.ry = vars()->player->y;
		vars()->rays.dof = 8;
	}
}

void	west_east(double ra)
{
	if ((ra > P2 && ra < P3) || (ra < P2 || ra > P3))
		vars()->rays.rx = (((int)vars()->player->x >> 6) << 6);
	if (ra > P2 && ra < P3)
	{
		vars()->rays.rx -= 0.0001;
		vars()->rays.xo = -CUBESIZE;
	}
	else
	{
		vars()->rays.rx += CUBESIZE;
		vars()->rays.xo = CUBESIZE;
	}
	vars()->rays.ry = (vars()->player->x - vars()->rays.rx) \
	* vars()->rays.ntan + vars()->player->y;
	vars()->rays.yo = -vars()->rays.xo * vars()->rays.ntan;
}

void	north_south(double ra)
{
	if (ra == 0 || ra == PI)
	{
		vars()->rays.rx = vars()->player->x;
		vars()->rays.ry = vars()->player->y;
		vars()->rays.dof = 8;
	}
}
