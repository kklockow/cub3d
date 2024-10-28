/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/28 13:04:39 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	leaks(void)
{
	system("leaks cub3D");
}

int_fast32_t	main(int_fast32_t ac, char **av)
{
	t_main	*main;

	// atexit(leaks);
	main = init_structs();
	parse_arguments(ac, av, main);
	init_data(main);
	mlx_loop_hook(main->mlx, fps, main);
	mlx_loop_hook(main->mlx, loop_hooks, main);
	mlx_key_hook(main->mlx, key_hooks, main);
	mlx_set_mouse_pos(main->mlx, main->mlx->width / 2, main->mlx->height / 2);
	mlx_loop(main->mlx);
	end_game(main);
	free_structs(main);
	return (0);
}
