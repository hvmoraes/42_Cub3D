/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:10:09 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/27 14:10:09 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	message(char *message)
{
	ft_putstr_fd(message, 2);
	return (FAILURE);
}

int	map_name(char *map)
{
	int	fd;

	if (map[ft_strlen(map) - 1] != 'b' && map[ft_strlen(map) - 2] != 'u'
		&& map[ft_strlen(map) - 3] != 'c')
		return (FAILURE);
	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

int	map_details(char *map)
{
	int	fd;
	int	error;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	error = 0;
	while(line)
	{
		//printf("%s\n", line);
		if (ft_strncmp(line, "NO ", 3) == 0)
			error += north(line);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			error += south(line);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			error += west(line);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			error += east(line);
		else if (ft_strncmp(line, "F ", 2) == 0)
			init_floor(line, &error);
		else if (ft_strncmp(line, "C ", 2) == 0)
			init_ceiling(line, &error);
		else if (ft_strchr(line, '1') == 0)
			error += init_map(line, fd);
		/*else
			error += message("Error\nInvalid character found\n");*/
		line = get_next_line(fd);
	}
	return(error);
}

int	parse(int argc, char **argv)
{
	data()->init_map = 0;
	(void)argv;
	if (argc != 2)
		return (message("Error\nWrong argument count\n"));
	if (!map_name(argv[1]))
		return (message("Error\nInvalid map passed\n"));
	if (!map_details(argv[1]))
		return (FAILURE);
	return (SUCCESS);
}
