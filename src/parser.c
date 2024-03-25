#include "../inc/cub3D.h"

int	init_floor_ceiling(char *str)
{
	char	**color;

	color = ft_split(ft_strrchr(str, ' '), ',');
	if (array_size(color) != 3 || !is_nbr(color[0]) \
	|| !is_nbr(color[1]) || !is_nbr(color[2]))
	{
		free_array(color);
		free(str);
		free_all(printf("Error\nWrong color\n"));
	}
	else
	{
		vars()->color.r = ft_atoi(color[0]);
		vars()->color.g = ft_atoi(color[1]);
		vars()->color.b = ft_atoi(color[2]);
		color_limits(&vars()->color.r, &vars()->color.g, &vars()->color.b);
	}
	free_array(color);
	return (rgb_to_int(vars()->color.r, vars()->color.g, vars()->color.b));
}

void	init_texture(t_img *img, char *line)
{
	if (img->img_ptr)
		mlx_destroy_image(vars()->win->mlx_ptr, img->img_ptr);
	img->img_ptr = mlx_xpm_file_to_image(vars()->win->mlx_ptr, \
		line + 3, &img->w, &img->h);
	if (!img->img_ptr)
	{
		free(line);
		free_all(printf("Error\nInvalid texture provided\n"));
		return ;
	}
	img->addr = mlx_get_data_addr(img->img_ptr, \
		&img->bpp, &img->line_len, &img->endian);
}

void	line_parser(char *line)
{
	if (*line == '\n')
		return ;
	else if (!ft_strncmp(line, "NO", 2) && vars()->no_cnt++ < 1)
		init_texture(&vars()->gra->no, line);
	else if (!ft_strncmp(line, "SO", 2) && vars()->so_cnt++ < 1)
		init_texture(&vars()->gra->so, line);
	else if (!ft_strncmp(line, "WE", 2) && vars()->we_cnt++ < 1)
		init_texture(&vars()->gra->we, line);
	else if (!ft_strncmp(line, "EA", 2) && vars()->ea_cnt++ < 1)
		init_texture(&vars()->gra->ea, line);
	else if (!ft_strncmp(line, "F", 1) && vars()->floor_cnt++ < 1)
		vars()->fcolor = init_floor_ceiling(line);
	else if (!ft_strncmp(line, "C", 1) && vars()->ceiling_cnt++ < 1)
		vars()->ccolor = init_floor_ceiling(line);
	else if (!(validate_string(line)) && !(check_string(line)))
	{
		if (++vars()->map_height && ft_strlen(line) > vars()->map_width)
			vars()->map_width = ft_strlen(line);
	}
}

void	parser(char *file)
{
	char	*line;
	int		fd;

	vars()->map_width = 0;
	vars()->map_height = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCould not open file\n");
		free_all(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		line_parser(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	line = NULL;
	close(fd);
}
