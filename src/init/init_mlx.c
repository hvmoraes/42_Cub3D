/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:41:53 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/03/01 14:41:53 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_mlx(void)
{
	data()->mlx = malloc(sizeof(t_mlx));
	data()->mlx->mlx = mlx_init();
	data()->mlx->win = mlx_new_window(data()->mlx->mlx, WIDTH, HEIGHT, "Cub3D");
	data()->mlx->img = mlx_new_image(data()->mlx->mlx, WIDTH, HEIGHT);
	data()->mlx->addr = mlx_get_data_addr(data()->mlx->img,
		&data()->mlx->bpp, &data()->mlx->ll, &data()->mlx->endian);
}
