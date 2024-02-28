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

typedef struct s_data {
	t_mlx	mlx;
	t_textures	textures;
	int	init_map;
}	t_data;