/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:47:20 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/03/01 14:47:20 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
	array = NULL;
}

void	free_parser(void)
{
	free_array(data()->map);
}

void	free_mlx(void)
{
	mlx_destroy_image(data()->mlx->mlx, data()->mlx->img);
	mlx_destroy_window(data()->mlx->mlx, data()->mlx->win);
	mlx_destroy_display(data()->mlx->mlx);
}

void	free_all(void)
{
	free(data()->mlx->mlx);
	free(data()->mlx);
}
