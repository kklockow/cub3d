/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map_layout.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:21:33 by kklockow          #+#    #+#             */
/*   Updated: 2024/10/19 15:08:23 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	character_check(char *to_check, t_main *main)
{
	int	i;

	i = 0;
	while (to_check[i] && to_check[i] != '\n')
	{
		i = skip_whitespaces(to_check, i);
		if (to_check[i] == '\0')
			return ;
		if (to_check[i] != '1' && to_check[i] != '0')
		{
			if (main->map_data->player_orientation != '\1')
				error_exit(main, ERR_WCF);
			else if (to_check[i] == 'N')
				main->map_data->player_orientation = 'N';
			else if (to_check[i] == 'E')
				main->map_data->player_orientation = 'E';
			else if (to_check[i] == 'S')
				main->map_data->player_orientation = 'S';
			else if (to_check[i] == 'W')
				main->map_data->player_orientation = 'W';
			else
				error_exit(main, ERR_WCF);
		}
		i++;
	}
}

bool	check_surrounding(char **map_layout, int y, int x)
{
	if (map_layout[y][x + 1] == ' ' || map_layout[y][x + 1] == '\0')
		return (false);
	if (map_layout[y + 1][x] == ' ' || map_layout[y + 1][x] == '\0')
		return (false);
	if (map_layout[y][x - 1] == ' ' || map_layout[y][x - 1] == '\0')
		return (false);
	if (map_layout[y - 1][x] == ' ' || map_layout[y - 1][x] == '\0')
		return (false);
	return (true);
}

void	border_check(char **map_layout, int y, t_main *main)
{
	int		x;
	char	player_orientation;

	x = 0;
	player_orientation = main->map_data->player_orientation;
	while (map_layout[y][x])
	{
		if (map_layout[y][x] == '0' || map_layout[y][x] == player_orientation)
		{
			if (y == 0 || x == 0)
				error_exit(main, ERR_NCW);
			if (map_layout[y + 1] == NULL)
				error_exit(main, ERR_NCW);
			if ((int)ft_strlen(map_layout[y - 1]) < x)
				error_exit(main, ERR_NCW);
			if ((int)ft_strlen(map_layout[y + 1]) < x)
				error_exit(main, ERR_NCW);
			if (check_surrounding(map_layout, y, x) == false)
				error_exit(main, ERR_NCW);
		}
		x++;
	}
}

void	check_map_layout(t_main *main)
{
	int	i;

	i = 0;
	while (main->map_data->map_layout[i])
	{
		character_check(main->map_data->map_layout[i], main);
		border_check(main->map_data->map_layout, i, main);
		i++;
	}
	if (main->map_data->player_orientation == '\1')
		error_exit(main, ERR_NPF);
}
