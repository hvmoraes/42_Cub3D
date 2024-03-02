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

int	check_mandatory()
{
	if (!data()->ceiling_cnt || !data()->floor_cnt || !data()->north_cnt
		|| !data()->south_cnt || !data()->west_cnt || !data()->east_cnt
		|| !data()->map_cnt || !data()->player_cnt)
		return (message("Error\nMissing element\n"));
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
		else if (ft_strchr(line, '1') != 0)
		{
			error += init_map(line, fd);
			close(fd);
			if (error == 0)
				error += check_mandatory();
			return (error);
		}
		line = get_next_line(fd);
	}
	if (error == 0)
		error += check_mandatory();
	close(fd);
	return(error);
}

int	parse(int argc, char **argv)
{
	data()->ceiling_cnt = 0;
	data()->floor_cnt = 0;
	data()->north_cnt = 0;
	data()->south_cnt = 0;
	data()->west_cnt = 0;
	data()->east_cnt = 0;
	data()->map_cnt = 0;
	data()->player_cnt = 0;
	data()->map = malloc(1000);
	(void)argv;
	if (argc != 2)
		return (message("Error\nWrong argument count\n"));
	if (!map_name(argv[1]))
		return (message("Error\nInvalid map passed\n"));
	if (!map_details(argv[1]))
		return (FAILURE);
	return (SUCCESS);
}
