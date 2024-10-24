/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_key_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:36:42 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/20 20:25:10 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	esc_key(t_main *main)
{
	if (mlx_is_key_down(main->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(main->mlx);
}

void	key_hooks(void *main)
{
	esc_key((t_main *)main);
	wasd_keys(((t_main *)main));
	arrow_keys((t_main *)main);
}
