/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:53:11 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/27 13:53:11 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_rgb {
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_mlx {
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
}	t_mlx;

typedef struct s_textures {
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_textures;

typedef struct s_player {
	char	initial_dir;
	float	dir;
} t_player;

typedef struct s_data {
	t_mlx	mlx;
	t_textures	textures;
	t_rgb floor;
	t_rgb	ceiling;
	int	ceiling_cnt;
	int	floor_cnt;
	int	north_cnt;
	int	south_cnt;
	int west_cnt;
	int	east_cnt;
	int	map_cnt;
	int	player_cnt;
	char	**map;
	t_player	player;
}	t_data;