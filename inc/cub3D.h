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

t_win	new_program(int w, int h, char *str);
t_img	new_img(int w, int h, t_win window);
void	put_pixel_img(t_img img, int x, int y, int color);
int		key_hook(int keycode);
int		exit_program(int exit_status);
t_var	*vars(void);
t_win	new_program(int w, int h, char *str);
void	draw_square(t_img img, int size, t_pos pos);
void	fill_image(t_img img, int color);
void	draw_rectagle(int width, int height, t_pos pos);
void	init_vars(void);
void	horizontal_check(double ra);
void	wall_color(void);
void	vertical_check(double ra);
void	initialize_game(char *file_path);
void	setup_player(void);
t_pos	initialize_player_position(void);
void	draw_player_and_rays(t_win window);
void	handle_hooks_and_put_image(t_win window);
void	line_vars(t_pos pos, int x1, int y1);
void	look_up_or_down(double ra);
void	look_left_or_right(double ra);
void	left_or_right(double ra);
void	up_or_down(double ra);
void	init_colors(void);
int		check_grid(void);
int		validate_string(char *input_str);
int		process_string(char *str);
int		is_valid_character(char current_char);
void	validate_aux(char current_char, int index);
int		render_hook(void);
int		check_string(char *input_str);
void	draw_3d_walls(void);
void	handle_exit(int keycode);
int		check_images(void);
void	draw_rays_2d(t_win window);
double	distance(int ax, int ay, int bx, int by);
int		get_pixel_img(t_img img, int pixel);
void	img_teste(t_img *img, char *line);
void	parser(char *filename);
int		check_format(const char *nome_arquivo);
void	color_limits(int *red, int *green, int *blue);
int		rgb_to_int(int red, int green, int blue);
int		check_count(void);
int		array_size(char **array);
void	free_array(char **array);
void	handle_movement_ws(int keycode);
void	handle_movement_ad(int keycode);

#endif
