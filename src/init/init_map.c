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
	int	old_error;

	if (data()->floor_cnt)
	{
		*error += message("Error\nOnly one Floor config allowed");
		return ;
	}
	data()->floor_cnt = 1;
	old_error = *error;
	floor_line = ft_split(line, ' ');
	if (array_size(floor_line) != 2)
	{
		*error += message("Error\nInvalid Floor config\n");
		free_array(floor_line);
		return ;
	}
	rgb = check_color(floor_line[1], error);
	free_array(floor_line);
	data()->floor.r = rgb.r;
	data()->floor.g = rgb.g;
	data()->floor.b = rgb.b;
	if (*error > old_error)
		message("Error\nInvalid Floor config\n");
}

void	init_ceiling(char *line, int *error)
{
	char	**ceiling_line;
	t_rgb	rgb;
	int	old_error;

	if (data()->ceiling_cnt)
	{
		*error += message("Error\nOnly one Floor config allowed");
		return ;
	}
	data()->ceiling_cnt = 1;
	old_error = *error;
	ceiling_line = ft_split(line, ' ');
	if (array_size(ceiling_line) != 2)
	{
		*error += message("Error\nInvalid Ceiling config\n");
		free_array(ceiling_line);
		return ;
	}
	rgb = check_color(ceiling_line[1], error);
	free_array(ceiling_line);
	data()->ceiling.r = rgb.r;
	data()->ceiling.g = rgb.g;
	data()->ceiling.b = rgb.b;
	if (*error > old_error)
		message("Error\nInvalid Ceiling config\n");
}

int	verify_top_bottom(int i)
{
	int	j;

	j = 0;
	while (data()->map[i][j])
	{
		if (data()->map[i][j] == '0')
			return (message("Error\nMap not closed\n"));
		else if (data()->map[i][j] != '1' && data()->map[i][j] != ' ')
			return (message("Error\nInvalid character found in map\n"));
		j++;
	}
	return (0);
}

void	calculate_dir(char p)
{
	if (p == 'N')
		data()->player.floatDir = 0.0;
	else if (p == 'S')
		data()->player.floatDir = M_PI;
	else if (p == 'E')
		data()->player.floatDir = M_PI / 2.0;
	else if (p == 'W')
		data()->player.floatDir = 3 * M_PI / 2;
	data()->player.dir.x = cos(data()->player.floatDir) * 5;
	data()->player.dir.y = sin(data()->player.floatDir) * 5;
	printf("dir x %f y %f\n", data()->player.dir.x, data()->player.dir.y);
}

int	verify_map()
{
	int	i;
	int	j;
	int	error;

	i = 0;
	error = 0;
	error += verify_top_bottom(i);
	i++;
	while (data()->map[i])
	{
		j = 0;
		while (data()->map[i][j])
		{
			while (data()->map[i][j] == ' ' || data()->map[i][j] == '\t')
				j++;
			if (data()->map[i][j] == '0' || data()->map[i][j] == 'N' || data()->map[i][j] == 'S'
				|| data()->map[i][j] == 'E' || data()->map[i][j] == 'W')
			{
				if (data()->map[i][j + 1] == ' ' || data()->map[i][j - 1] == ' '
					|| data()->map[i + 1][j] == ' ' || data()->map[i - 1][j] == ' '
					|| data()->map[i + 1][j + 1] == ' ' || data()->map[i + 1][j - 1] == ' '
					|| data()->map[i - 1][j + 1] == ' ' || data()->map[i - 1][j - 1] == ' ')
					return (message("Error\nMap not closed\n"));
				if (data()->map[i][j] == 'N' || data()->map[i][j] == 'S'
					|| data()->map[i][j] == 'E' || data()->map[i][j] == 'W')
				{
					if (data()->player_cnt)
						return (message("Error\nOnly one player start position allowed\n"));
					data()->player_cnt++;
					data()->player.pos.x = i;
					data()->player.pos.y = j;
					calculate_dir(data()->map[i][j]);
					//printf("%c\n", data()->player.initial_dir);
				}
			}
			//printf("%c", data()->map[i][j]);
			j++;
		}
		//printf("\n");
		i++;
	}
	error += verify_top_bottom(i - 1);
	return (error);
}

int	valid_map_line(char *line)
{
	int	i;

	i = 0;
	while(line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != '\t')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	init_map(char *line, int fd)
{
	int	i;

	i = 0;
	data()->map_cnt = 1;
	while (line)
	{
		//printf("%s\n", line);
		//printf("%s %s\n", ft_strchr(line, '1'), ft_strchr(line, '0'));
		if (valid_map_line(line))
			return (message("Error\nInvalid character found\n"));
		if (ft_strchr(line, '1') || ft_strchr(line, '0'))
		{
			//printf("PUTA Q PARIU\n");
			data()->map[i] = ft_strdup(line);
			//printf("%s\n", data()->map[i]);
			i++;
		}
		else if (line[0])
			return (message("Error\nInvalid map\n"));
		line = get_next_line(fd);
	}
	data()->map[i] = NULL;
	/*for (int j = 0; data()->map[j]; j++)
		printf("%s\n", data()->map[j]);*/
	return (verify_map());
}


/* Se encontrar um zero, verificar se tudo a volta e 1 ou 0, nao pode ser espaco:
for (int i = 0; data().map[i]; i++)
{
	for (int j = 0; data[i][j]; j++)
	{
		if (data[i][j] == '0')
		{
			if (data[i][j + 1] == ' ' || data[i][j - 1] == ' ' || data[i + 1][j] == ' ' || data[i - 1][j] == ' ' || data[i + 1][j + 1] == ' ' || data[i + 1][j - 1] == ' ' || data[i - 1][j + 1] == ' ' || data[i - 1][j - 1] == ' ')
		}
	}
}
*/
