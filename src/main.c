/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:32:55 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/02/27 11:32:55 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	if (parse(argc, argv))
	{
		free_parser();
		return (FAILURE);
	}
	else
		run();
	return (SUCCESS);
}
