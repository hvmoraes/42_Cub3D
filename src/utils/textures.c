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
	//char	**fuck;

	//line = remove_el(line);
	//fuck = ft_split(line, '\n');
	//printf("FDSSS\n.%s.\nFDSSS", fuck[0]);
	//printf("\nIMAGINA %s.\n", line);
	if (line[ft_strlen(line) - 1] != '\n' && line[ft_strlen(line) - 2] != 'm'
		&& line[ft_strlen(line) - 3] != 'p' && line[ft_strlen(line) - 4] != 'x')
		return (message("Error\nInvalid texture name\n"));
	fd = open(line, O_RDONLY);
	/*if (fd == -1)
	{
		close(fd);
		return (message("Error\nCannot open texture file\n"));
	}*/
	close(fd);
	return(SUCCESS);
}

int	north(char *line)
{
	char **texture;

	texture = ft_split(line, ' ');
	if (data()->init_map == 1)
		return (message("Error\nMap has to be the last thing in the file\n"));
	if (array_size(texture) != 2)
		return (message("Error\nInvalid texture line arguments count\n"));
	if (!format(texture[1]))
		return (FAILURE);
	data()->textures.north = texture[1];
	return (SUCCESS);
}

int	south(char *line)
{
	char **texture;

	texture = ft_split(line, ' ');
	if (data()->init_map == 1)
		return (message("Error\nMap has to be the last thing in the file\n"));
	if (array_size(texture) != 2)
		return (message("Error\nInvalid texture line arguments count\n"));
	if (!format(texture[1]))
		return (FAILURE);
	data()->textures.south = texture[1];
	return (SUCCESS);
}

int	west(char *line)
{
	char **texture;

	texture = ft_split(line, ' ');
	if (data()->init_map == 1)
		return (message("Error\nMap has to be the last thing in the file\n"));
	if (array_size(texture) != 2)
		return (message("Error\nInvalid texture line arguments count\n"));
	if (!format(texture[1]))
		return (FAILURE);
	data()->textures.west = texture[1];
	return (SUCCESS);
}

int	east(char *line)
{
	char **texture;

	texture = ft_split(line, ' ');
	if (data()->init_map == 1)
		return (message("Error\nMap has to be the last thing in the file\n"));
	if (array_size(texture) != 2)
		return (message("Error\nInvalid texture line arguments count\n"));
	if (!format(texture[1]))
		return (FAILURE);
	data()->textures.east = texture[1];
	return (SUCCESS);
}
