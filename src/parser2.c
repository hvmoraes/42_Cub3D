#include "../inc/cub3D.h"

void	validate_aux(char current_char, int index)
{
	vars()->player->orientation = current_char;
	vars()->player->startx = index;
	vars()->player->starty = vars()->map_height;
}

int	check_count(void)
{
	if (vars()->player_cnt != 1 || vars()->no_cnt != 1 \
	|| vars()->so_cnt != 1 || vars()->we_cnt != 1 \
	|| vars()->ea_cnt != 1 || vars()->floor_cnt != 1 \
	|| vars()->ceiling_cnt != 1)
		return (0);
	return (1);
}

int	array_size(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		continue ;
	return (i);
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
