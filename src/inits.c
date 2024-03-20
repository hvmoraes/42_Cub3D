#include "../inc/cub3D.h"

void	init_vars(void)
{
	t_rays	*rays;

	rays = &(vars()->rays);
	rays->dist = 0;
	rays->xo = 0;
	rays->yo = 0;
	rays->rx = 0;
	rays->ry = 0;
	rays->angle = vars()->player->angle - (vars()->dr * SCREENWIDTH / 2);
	while (rays->angle < 0)
		rays->angle += 2 * PI;
	while (rays->angle >= 2 * PI)
		rays->angle -= 2 * PI;
}

t_pos	initialize_player_position(void)
{
	t_pos		pos;
	t_player	*player;

	player = vars()->player;
	pos.x = player->startx * CUBESIZE + CUBESIZE / 2;
	pos.y = player->starty * CUBESIZE + CUBESIZE / 2;
	player->x = pos.x;
	player->y = pos.y;
	pos.color = rgb_to_int(255, 255, 0);
	return (pos);
}

void	setup_player(void)
{
	if (vars()->player->orientation == 'N')
		vars()->player->angle = -P2;
	else if (vars()->player->orientation == 'S')
		vars()->player->angle = P2;
	else if (vars()->player->orientation == 'E')
		vars()->player->angle = 0;
	else if (vars()->player->orientation == 'W')
		vars()->player->angle = PI;
	vars()->player->delta_x = cos(vars()->player->angle) * 5;
	vars()->player->delta_y = sin(vars()->player->angle) * 5;
}

void	init_vars2(void)
{
	static t_player		player;

	vars()->gra = malloc(sizeof(t_gra));
	vars()->gra->no.img_ptr = NULL;
	vars()->gra->so.img_ptr = NULL;
	vars()->gra->we.img_ptr = NULL;
	vars()->gra->ea.img_ptr = NULL;
	vars()->gra->canvas.img_ptr = NULL;
	vars()->player_cnt = 0;
	vars()->no_cnt = 0;
	vars()->so_cnt = 0;
	vars()->we_cnt = 0;
	vars()->ea_cnt = 0;
	vars()->floor_cnt = 0;
	vars()->ceiling_cnt = 0;
	vars()->player = &player;
}

void	initialize_game(char *file_path)
{
	static t_win		window;
	static t_img		player_img;

	init_vars2();
	window = new_program(SCREENWIDTH, SCREENHEIGHT, "cub3d");
	vars()->win = &window;
	if (!check_format(file_path))
		exit_program(printf("Error:\nWrong file extension\n") != 0);
	parser(file_path);
	if (!check_count())
		exit_program(printf("Error\nWrong number of elements\n"));
	if (!check_images())
		exit_program(printf("Error\nWrong texture path\n") != 0);
	if (!check_grid() || !vars()->player->orientation)
		exit_program(printf("Error\nInvalid map\n") != 0);
	player_img = new_img(SCREENWIDTH, SCREENHEIGHT, window);
	vars()->gra->canvas = player_img;
	setup_player();
	draw_player_and_rays(window);
	handle_hooks_and_put_image(window);
}
