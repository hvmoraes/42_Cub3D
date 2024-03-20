#include "../inc/cub3D.h"

int	is_nbr(char *nbr)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]) && nbr[i] != ' ' && nbr[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	process_string(char *str)
{
	char **color;

	color = ft_split(ft_strrchr(str, ' '), ',');
	if (array_size(color) != 3 || !is_nbr(color[0]) || !is_nbr(color[1]) || !is_nbr(color[2]))
	{
		free_array(color);
		free(str);
		exit_program(printf("Error\nWrong color\n"));
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

int	 process_character(char *input_str, int index)
{
	char	current_char;

	current_char = input_str[index];
	if (!is_valid_character(current_char))
	{
		free(input_str);
		exit_program(printf("Error\nInvalid character\n") != 0);
	}
	if (current_char == 'N' || current_char == 'S' || \
		current_char == 'E' || current_char == 'W')
	{
		vars()->player_cnt++;
		validate_aux(current_char, index);
		current_char = '0';
	}
	if (current_char == ' ')
		current_char = '2';
	vars()->map[vars()->map_height][index] = (current_char - '0');
	return (0);
}

void	fill_map_line(int index)
{
	while (index < MAXSIZE)
	{
		vars()->map[vars()->map_height][index] = 2;
		index++;
	}
}

int	validate_string(char *input_str)
{
	int	index;

	index = 0;
	vars()->player->angle = 0;
	while (input_str[index] != '\0')
	{
		if (process_character(input_str, index) != 0)
			return (1);
		index++;
	}
	fill_map_line(index);
	return (0);
}

int	check_format(const char *nome_arquivo)
{
	const char	*extensao;

	extensao = ft_strrchr(nome_arquivo, '.');
	if (extensao != NULL)
	{
		if (ft_strcmp(extensao, ".cub") == 0)
			return (1);
	}
	return (0);
}
