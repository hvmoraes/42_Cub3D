#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "../Libft/inc/libft.h"
# include "structs.h"
# include "defines.h"

t_img	new_image(int w, int h, t_win window);
void	put_pixel(t_img img, int x, int y, int color);
int		key_hook(int keycode);
int		free_all(int exit_status);
t_var	*vars(void);
t_win	init_window(int w, int h, char *str);
void	draw_floor_ceiling(int width, int height, t_pos pos);
void	init_rays(void);
void	check_horizontal(double ra);
void	wall_color(void);
void	check_vertical(double ra);
void	inits(char *file_path);
void	init_player(void);
t_pos	init_player_pos(void);
void	draw_all(void);
void	look_north_south(double ra);
void	look_west_east(double ra);
void	west_east(double ra);
void	north_south(double ra);
void	init_colors(void);
int		check_map(void);
int		validate_string(char *input_str);
int		render_hook(void);
int		check_string(char *input_str);
void	handle_exit(int keycode);
int		check_images(void);
void	rays(void);
double	distance(int ax, int ay, int bx, int by);
int		get_pixel(t_img img, int pixel);
void	parser(char *file);
int		check_format(const char *file);
void	color_limits(int *red, int *green, int *blue);
int		rgb_to_int(int red, int green, int blue);
int		check_count(void);
int		array_size(char **array);
void	free_array(char **array);
int		is_nbr(char *nbr);
t_img	wall_image(void);
void	wall_collision(void);
void	draw_utils(void);

#endif
