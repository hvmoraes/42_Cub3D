/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:25:17 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/27 15:25:17 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_floor(char *line, int *error)
{
	char	**floor_line;
	t_rgb	rgb;
	//int	old_error;

	//old_error = *error;
	floor_line = ft_split(line, ' ');
	rgb = check_color(floor_line[1], error);
	data()->floor.r = rgb.r;
	data()->floor.g = rgb.g;
	data()->floor.b = rgb.b;
	//printf("r %i g %i b %i\n", data()->floor.r, data()->floor.g, data()->floor.b);
	/*if (*error > old_error)
		message("Error\nInvalid Floor config\n");*/
}

void	init_ceiling(char *line, int *error)
{
	char	**ceiling_line;
	t_rgb	rgb;
	//int	old_error;

	//old_error = *error;
	ceiling_line = ft_split(line, ' ');
	rgb = check_color(ceiling_line[1], error);
	data()->ceiling.r = rgb.r;
	data()->ceiling.g = rgb.g;
	data()->ceiling.b = rgb.b;
	/*if (*error > old_error)
		message("Error\nInvalid Ceiling config\n");*/
}

int	init_map(char *line, int fd)
{
	int	i;

	data()->init_map = 1;
	data()->map = malloc(1000);
	i = 0;
	while (line)
	{
		data()->map[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	printf("FDS\n");
	for (int j = 0; data()->map[j]; j++)
		printf("%s", data()->map[j]);
	return (SUCCESS);
}	
