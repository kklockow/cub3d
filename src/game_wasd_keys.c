/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_wasd_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:44:12 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/22 13:14:07 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_key(t_main *main, t_point pos, t_vec dist)
{
	char	**map;

	map = main->map_data->map_coor;
	if (mlx_is_key_down(main->mlx, MLX_KEY_W))
	{
		if (map[(int)(pos.x + dist.x)][(int)(pos.y)] != '1')
			pos.x += dist.x;
		if (main->map_data->map_coor[(int)pos.x][(int)(pos.y + dist.y)] != '1')
			pos.y += dist.y;
	}
}

void	a_key(t_main *main, t_point pos, t_vec dist)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_A))
	{
		new.x = (int)(pos.x + dist.y);
		new.y = (int)(pos.y - dist.x);
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[pos.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][pos.x] != '1'))
		{
			pos.y -= dist.x;
			pos.x += dist.y;
		}
	}
}

void	s_key(t_main *main, t_point pos, t_vec dist)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_S))
	{
		new.x = (int)(pos.x - dist.x);
		new.y = (int)(pos.y - dist.y);
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[pos.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][pos.x] != '1'))
		{
			pos.y -= dist.y;
			pos.x -= dist.x;
		}
	}
}

void	d_key(t_main *main, t_point pos, t_vec dist)
{
	t_point	new;

	if (mlx_is_key_down(main->mlx, MLX_KEY_D))
	{
		new.x = (int)(pos.x - dist.y);
		new.y = (int)(pos.y + dist.x);
		if (main->map_data->map_coor[new.y][new.x] != '1'
			&& (main->map_data->map_coor[pos.y][new.x] != '1'
				|| main->map_data->map_coor[new.y][pos.x] != '1'))
		{
			pos.y += dist.x;
			pos.x -= dist.y;
		}
	}
}

void	wasd_keys(t_main *main)
{
	t_point	player_pos;
	t_vec	dist;

	player_pos.x = (int)(main->player->pos.x);
	player_pos.y = (int)(main->player->pos.y);
	dist.y = main->player->dir.y * main->player->speed;
	dist.x = main->player->dir.x * main->player->speed;
	w_key(main, player_pos, dist);
	a_key(main, player_pos, dist);
	s_key(main, player_pos, dist);
	d_key(main, player_pos, dist);
}
