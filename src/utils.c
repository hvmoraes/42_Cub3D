/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:12:14 by roda-min          #+#    #+#             */
/*   Updated: 2024/04/08 15:12:15 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	init_trig_lut(void)
{
	int		i;
	double	a;

	i = 0;
	while (i < LUT_SIZE)
	{
		a = i * LUT_STEP;
		vars()->sin_lut[i] = sin(a);
		vars()->cos_lut[i] = cos(a);
		vars()->tan_lut[i] = tan(a);
		i++;
	}
}

static int	lut_index(double angle)
{
	int	idx;

	while (angle < 0)
		angle += 2 * PI;
	while (angle >= 2 * PI)
		angle -= 2 * PI;
	idx = (int)(angle / LUT_STEP);
	if (idx < 0)
		idx = 0;
	if (idx >= LUT_SIZE)
		idx = LUT_SIZE - 1;
	return (idx);
}

double	lut_sin(double angle)
{
	return (vars()->sin_lut[lut_index(angle)]);
}

double	lut_cos(double angle)
{
	return (vars()->cos_lut[lut_index(angle)]);
}

double	lut_tan(double angle)
{
	return (vars()->tan_lut[lut_index(angle)]);
}
