#include "../inc/cub3D.h"

void	parseline(char *line)
{
	if (*line == '\n')
		return ;
	else if (!ft_strncmp(line, "NO", 2) && vars()->no_cnt++ < 1)
		img_teste(&vars()->graphics->no, line);
	else if (!ft_strncmp(line, "SO", 2) && vars()->so_cnt++ < 1)
		img_teste(&vars()->graphics->so, line);
	else if (!ft_strncmp(line, "WE", 2) && vars()->we_cnt++ < 1)
		img_teste(&vars()->graphics->we, line);
	else if (!ft_strncmp(line, "EA", 2) && vars()->ea_cnt++ < 1)
		img_teste(&vars()->graphics->ea, line);
	else if (!ft_strncmp(line, "F", 1) && vars()->floor_cnt++ < 1)
		vars()->fcolor = process_string(line);
	else if (!ft_strncmp(line, "C", 1) && vars()->ceiling_cnt++ < 1)
		vars()->ccolor = process_string(line);
	else if (!(validate_string(line)) && !(check_string(line)))
	{
		if (++vars()->map_height && ft_strlen(line) > vars()->map_width)
			vars()->map_width = ft_strlen(line);
	}
}

void	parser(char *filename)
{
	char	*line;
	int		fd;

	vars()->map_width = 0;
	vars()->map_height = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCould not open file\n");
		exit_program(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		parseline(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close(fd);
}

void	fill_image(t_img img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < img.w)
	{
		j = 0;
		while (j++ < img.h)
			put_pixel_img(img, i, j, color);
	}
}

int	check_string(char *input_str)
{
	while (*input_str != '\0')
	{
		if (*input_str == '0' || *input_str == '1')
			return (0);
		input_str++;
	}
	return (1);
}

int	is_valid_character(char current_char)
{
	if ((current_char - '0') == 0 || (current_char - '0') == 1 || \
		current_char == 'N' || current_char == 'S' || \
		current_char == 'E' || current_char == 'W' || \
		current_char == ' ')
		return (1);
	else
		return (0);
}
