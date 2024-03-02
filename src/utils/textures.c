/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:52:38 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/27 14:52:38 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	format(char *line)
{
	int	fd;

	if (line[ft_strlen(line) - 1] != 'm'
		&& line[ft_strlen(line) - 2] != 'p' && line[ft_strlen(line) - 3] != 'x')
		return (message("Error\nInvalid texture name\n"));
	fd = open(line, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (message("Error\nCannot open texture file\n"));
	}
	close(fd);
	return(SUCCESS);
}

int	north(char *line)
{
	char **texture;

	if (data()->north_cnt)
		return (message("Error\nOnly one north texture allowed"));
	data()->north_cnt = 1;
	texture = ft_split(line, ' ');
	if (array_size(texture) != 2)
		return (message("Error\nInvalid texture line arguments count\n"));
	if (!format(texture[1]))
		return (FAILURE);
	data()->textures.north = texture[1];
	free_array(texture);
	return (SUCCESS);
}

int	south(char *line)
{
	char **texture;

	if (data()->south_cnt)
		return (message("Error\nOnly one south texture allowed"));
	data()->south_cnt = 1;
	texture = ft_split(line, ' ');
	if (array_size(texture) != 2)
		return (message("Error\nInvalid texture line arguments count\n"));
	if (!format(texture[1]))
		return (FAILURE);
	data()->textures.south = texture[1];
	free_array(texture);
	return (SUCCESS);
}

int	west(char *line)
{
	char **texture;

	if (data()->west_cnt)
		return (message("Error\nOnly one west texture allowed"));
	data()->west_cnt = 1;
	texture = ft_split(line, ' ');
	if (array_size(texture) != 2)
		return (message("Error\nInvalid texture line arguments count\n"));
	if (!format(texture[1]))
		return (FAILURE);
	data()->textures.west = texture[1];
	free_array(texture);
	return (SUCCESS);
}

int	east(char *line)
{
	char **texture;

	if (data()->east_cnt)
		return (message("Error\nOnly one east texture allowed"));
	data()->east_cnt = 1;
	texture = ft_split(line, ' ');
	if (array_size(texture) != 2)
		return (message("Error\nInvalid texture line arguments count\n"));
	if (!format(texture[1]))
		return (FAILURE);
	data()->textures.east = texture[1];
	free_array(texture);
	return (SUCCESS);
}
