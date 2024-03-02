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

int	render(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			put_pixel(i, j, 0);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data()->mlx->mlx, data()->mlx->win,
		data()->mlx->img, 0, 0);
	return (SUCCESS);
}

int	close_window(void)
{
	free_mlx();
	free_all();
	exit(0);
	return (SUCCESS);
}

int	key_hooks(int keycode)
{
	if (keycode == 65307)
		close_window();
	printf("keycode = %i\n", keycode);
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
	ft_putstr_fd("Congrats! Valid map passed!\n", 1);
}
