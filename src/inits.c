#include "../inc/cub3D.h"

// void	init_vars(void)
// {
// 	vars()->rays.rx = 0;
// 	vars()->rays.ry = 0;
// 	vars()->rays.xo = 0;
// 	vars()->rays.yo = 0;
// 	vars()->rays.dist = 0;
// 	vars()->rays.ra = vars()->player->angle - (vars()->dr * SCREENWIDTH / 2);
// 	if (vars()->rays.ra < 0)
// 		vars()->rays.ra += 2 * PI;
// 	if (vars()->rays.ra >= 2 * PI)
// 		vars()->rays.ra -= 2 * PI;
// }

void init_vars(void)
{
    t_rays *rays = &(vars()->rays);

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

// t_pos	initialize_player_position(void)
// {
// 	t_pos	pos;

// 	pos.x = vars()->player->startx * CUBESIZE + CUBESIZE / 2;
// 	pos.y = vars()->player->starty * CUBESIZE + CUBESIZE / 2;
// 	pos.color = rgb_to_int(255, 255, 0);
// 	vars()->player->x = pos.x;
// 	vars()->player->y = pos.y;
// 	return (pos);
// }

t_pos initialize_player_position(void)
{
    t_pos pos;
    t_player *player = vars()->player;

    pos.x = player->startx * CUBESIZE + CUBESIZE / 2;
    pos.y = player->starty * CUBESIZE + CUBESIZE / 2;

    player->x = pos.x;
    player->y = pos.y;

    pos.color = rgb_to_int(255, 255, 0);

    return (pos);
}


// void	setup_player(void)
// {
// 	if (vars()->player->orientation == 'N')
// 		vars()->player->angle = -P2;
// 	else if (vars()->player->orientation == 'S')
// 		vars()->player->angle = P2;
// 	else if (vars()->player->orientation == 'E')
// 		vars()->player->angle = 0;
// 	else if (vars()->player->orientation == 'W')
// 		vars()->player->angle = PI;
// 	vars()->player->delta_x = cos(vars()->player->angle) * 5;
// 	vars()->player->delta_y = sin(vars()->player->angle) * 5;
// }

#include <stdio.h> // Include necessary headers

void	setup_player(void)
{
	t_player *player = vars()->player;
	
	// Define a lookup table mapping orientations to angles
	t_oam ori_ang[] = {
        {'N', -P2},
        {'S', P2},
        {'E', 0},
        {'W', PI}
    };

    // Initialize index and found flag
    size_t i = 0;
    int found = 0;

    // Iterate over the lookup table using a while loop
    while (i < sizeof(ori_ang) / sizeof(ori_ang[0]) && !found) 
	{
        if (player->orientation == ori_ang[i].orientation) {
            player->angle = ori_ang[i].angle;
            found = 1; // Set found flag to exit loop
        }
        i++; // Increment index
    }

    // Calculate player deltas
    player->delta_x = cos(player->angle) * 5;
    player->delta_y = sin(player->angle) * 5;
}



void	initialize_game(char *file_path)
{
	static t_win		window;
	static t_player		player;
	static t_img		player_img;

	vars()->graphics = malloc(sizeof(t_graphics));
	vars()->graphics->no.img_ptr = NULL;
	vars()->graphics->so.img_ptr = NULL;
	vars()->graphics->we.img_ptr = NULL;
	vars()->graphics->ea.img_ptr = NULL;
	vars()->graphics->canvas.img_ptr = NULL;
	vars()->player_cnt = 0;
	vars()->no_cnt = 0;
	vars()->so_cnt = 0;
	vars()->we_cnt = 0;
	vars()->ea_cnt = 0;
	vars()->floor_cnt = 0;
	vars()->ceiling_cnt = 0;
	vars()->player = &player;
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
	vars()->graphics->canvas = player_img;
	setup_player();
	draw_player_and_rays(window);
	handle_hooks_and_put_image(window);
}

// void	init_colors(void)
// {
// 	vars()->color.r = 0;
// 	vars()->color.g = 0;
// 	vars()->color.b = 0;
// }

void init_colors(void)
{
    t_color *color = &(vars()->color); // Pointer to the t_color structure

    // Set color components
    color->r = 0;
    color->g = 0;
    color->b = 0;
}
