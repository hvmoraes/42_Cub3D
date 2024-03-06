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

# define SUCCESS 0
# define FAILURE 1
# define WIDTH 960
# define HEIGHT 540
# define INF 2147483647
# define BLACK 0
# define WHITE 16777215
# define RED 16711680
# define BLUE 255
# define GREEN 65280
# define YELLOW 16776960
# define FOV 53
# define DR 0.0174532925

int		message(char *message);
int		parse(int argc, char **argv);

void		init_floor(char *line, int *error);
void		init_ceiling(char *line, int *error);
int		init_map(char *line, int fd);

void	init_mlx(void);

void	run(void);

int		north(char *line);
int		south(char *line);
int		west(char *line);
int		east(char *line);

char	*remove_el(char *line);

int		array_size(char **array);

t_rgb	check_color(char *color, int *error);

t_data	*data(void);

void	free_array(char **array);
void	free_parser(void);
void	free_mlx(void);
void	free_all(void);