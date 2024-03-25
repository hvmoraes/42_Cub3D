/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:52:58 by neves             #+#    #+#             */
/*   Updated: 2024/03/25 14:52:59 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	free_all(int exit_status)
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

void	handle_exit(int keycode)
{
	if (keycode == ESC_KEY_M || keycode == CROSS)
		free_all(0);
}
