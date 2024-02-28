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

int	init_floor(char *line)
{
	(void)line;
	return (SUCCESS);
}

int	init_ceiling(char *line)
{
	(void)line;
	return (SUCCESS);
}

int	init_map(char *line, int fd)
{
	(void)fd;
	(void)line;
	data()->init_map = 1;
	/*while (line)
	{

		line = get_next_line(fd);
	}*/
	return (SUCCESS);
}	
