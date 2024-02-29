/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:27:40 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/29 09:27:40 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_rgb	color_overflow(t_rgb final_color)
{
	if (final_color.r > 255)
		final_color.r = 255;
	if (final_color.r < 0)
		final_color.r = 0;
	if (final_color.g > 255)
		final_color.g = 255;
	if (final_color.g < 0)
		final_color.g = 0;
	if (final_color.b > 255)
		final_color.b = 255;
	if (final_color.b < 0)
		final_color.b = 0;
	return (final_color);
}

t_rgb	check_color(char *color, int *error)
{
	int		i;
	t_rgb	final_color;
	char	**color_vec;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]) && color[i] != ','
			&& color[i] != '\n' && color[i] != '\0')
			*error += 1;
		i++;
	}
	color_vec = ft_split(color, ',');
	if (array_size(color_vec) != 3)
		*error += 1;
	else
	{
		final_color.r = ft_atoi(color_vec[0]);
		final_color.g = ft_atoi(color_vec[1]);
		final_color.b = ft_atoi(color_vec[2]);
		//printf("%i\n", *error);
		//free_array(color_vec);
		final_color = color_overflow(final_color);
	}
	return (final_color);
}
