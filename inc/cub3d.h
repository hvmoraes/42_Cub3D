/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:32:37 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/27 11:32:37 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../Libft/inc/libft.h"
# include "structs.h"

#define SUCCESS 1
#define FAILURE 0

int		message(char *message);
int		parse(int argc, char **argv);

void		init_floor(char *line, int *error);
void		init_ceiling(char *line, int *error);
int		init_map(char *line, int fd);

void	run(void);

int		north(char *line);
int		south(char *line);
int		west(char *line);
int		east(char *line);

char	*remove_el(char *line);

int		array_size(char **array);

t_rgb	check_color(char *color, int *error);

t_data	*data(void);