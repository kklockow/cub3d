/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:38:24 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/28 13:08:57 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_hooks(void *param)
{
	t_main	*main;

	main = (t_main *)param;
	// ft_bzero(main->image->pixels, main->mlx->width * main->mlx->height
	// 	* sizeof(uint32_t));
	if (main->texture_toggle_floor == true)
	{
		draw_floor_textured(main);
		draw_ceiling_textured(main);
	}
	else
		draw_background_colored(main);
	if (main->texture_toggle_walls == true)
		render_3d_textured(main);
	else
		render_3d_colored(main);
	if (MINIMAP == true)
		draw_minimap(main);
	wasd_keys(((t_main *)main));
	arrow_keys((t_main *)main);
	if (main->mouse_toggle == true)
		mouse_movement((t_main *)main);
	main->frame++;
	// crouch((t_main *)main);
}
