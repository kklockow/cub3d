/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:28:23 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/25 13:29:10 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* ------------------------------ INIT TEXTURES ----------------------------- */
// mlx_texture_t

// mlx_texture_t* mlx_load_png(const char* path);
void	load_textures(t_main *main)
{
	main->textures[NORTH] = NULL;
	main->textures[EAST] = NULL;
	main->textures[SOUTH] = NULL;
	main->textures[WEST] = NULL;
	main->textures[CEILING] = NULL;
	main->textures[FLOOR] = NULL;
	main->textures[6] = NULL;
	main->textures[NORTH] = mlx_load_png(main->map_data->north_texture);
	if (main->textures[NORTH] == NULL)
		error_exit(main, mlx_errno);
	main->textures[EAST] = mlx_load_png(main->map_data->west_texture);
	if (main->textures[EAST] == NULL)
		error_exit(main, mlx_errno);
	main->textures[WEST] = mlx_load_png(main->map_data->west_texture);
	if (main->textures[WEST] == NULL)
		error_exit(main, mlx_errno);
	main->textures[CEILING] = mlx_load_png("./textures/ceiling.png");
	if (main->textures[CEILING] == NULL)
		error_exit(main, mlx_errno);
	main->textures[FLOOR] = mlx_load_png("./textures/floor.png");
	if (main->textures[FLOOR] == NULL)
		error_exit(main, mlx_errno);
}
