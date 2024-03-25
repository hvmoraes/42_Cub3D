/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:50:40 by neves             #+#    #+#             */
/*   Updated: 2024/03/25 14:50:40 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_borders(int i, int j)
{
	return (i == vars()->map_height - 1 || \
	j == 0 || j == vars()->map_width - 1 || i == 0);
}

int	check_neighbors(int i, int j)
{
	if (i > 0 && vars()->map[i - 1][j] == 0)
		return (0);
	if (i < vars()->map_height - 1 && vars()->map[i + 1][j] == 0)
		return (0);
	if (j > 0 && vars()->map[i][j - 1] == 0)
		return (0);
	if (j < vars()->map_width - 1 && vars()->map[i][j + 1] == 0)
		return (0);
	return (1);
}

int	check_map(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars()->map_height)
	{
		j = 0;
		while (j < vars()->map_width)
		{
			if (vars()->map[i][j] == 2 || \
			(vars()->map[i][j] == vars()->player->orientation))
			{
				if (!check_neighbors(i, j))
					return (0);
			}
			if (vars()->map[i][j] == 0 && check_borders(i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
