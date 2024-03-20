#include "../inc/cub3D.h"

/**
 * @brief Check if ESC or cross have been pressed and close program
 * 
 * @param keycode 
 */
void	handle_exit(int keycode)
{
	if (keycode == ESC_KEY_M || keycode == CROSS)
		exit_program(0);
}

/**
 * @brief 
 * 
 * @param i 
 * @param j 
 * @return int 
 */
int	check_borders(int i, int j)
{
	return (i == vars()->map_height - 1 || \
	j == 0 || j == vars()->map_width - 1 || i == 0);
}

// Function to check neighboring cells
// int	check_neighbors(int i, int j)
// {
// 	if (i > 0 && vars()->map[i - 1][j] == 0)
// 		return (0);
// 	if (i < vars()->map_height - 1 && vars()->map[i + 1][j] == 0)
// 		return (0);
// 	if (j > 0 && vars()->map[i][j - 1] == 0)
// 		return (0);
// 	if (j < vars()->map_width - 1 && vars()->map[i][j + 1] == 0)
// 		return (0);
// 	return (1);
// }

int check_neighbors(int i, int j) {
    int dx[] = {-1, 1, 0, 0}; // Changes in row indices
    int dy[] = {0, 0, -1, 1}; // Changes in column indices
    int k = 0;

    while (k < 4) {
        int ni = i + dx[k]; // Neighbor row index
        int nj = j + dy[k]; // Neighbor column index

        if (ni >= 0 && ni < vars()->map_height && nj >= 0 && nj < vars()->map_width) {
            if (vars()->map[ni][nj] == 0) {
                return 0; // At least one neighbor is zero
            }
        }

        k++;
    }

    return 1; // No neighbors are zero
}


// Function to check the entire grid
// int	check_grid(void)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < vars()->map_height)
// 	{
// 		j = 0;
// 		while (j < vars()->map_width)
// 		{
// 			if (vars()->map[i][j] == 2 || 
// 			(vars()->map[i][j] == vars()->player->orientation))
// 			{
// 				if (!check_neighbors(i, j))
// 					return (0);
// 			}
// 			if (vars()->map[i][j] == 0 && check_borders(i, j))
// 				return (0);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int check_grid(void) {
    int index = 0;
    int valid = 1; // Assume the grid is valid initially

    while (index < vars()->map_height * vars()->map_width && valid) {
        int row = index / vars()->map_width;
        int col = index % vars()->map_width;

        if ((vars()->map[row][col] == 2 || vars()->map[row][col] == vars()->player->orientation) && !check_neighbors(row, col)) {
            valid = 0; // Grid is invalid if neighbors check fails
        }
        if (vars()->map[row][col] == 0 && check_borders(row, col)) {
            valid = 0; // Grid is invalid if border check fails
        }

        index++;
    }

    return valid;
}


int	check_images(void)
{
	if (vars()->graphics->no.img_ptr && vars()->graphics->so.img_ptr && \
	vars()->graphics->we.img_ptr && vars()->graphics->ea.img_ptr)
		return (1);
	return (0);
}
