/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:36:14 by kklockow          #+#    #+#             */
/*   Updated: 2024/08/27 19:01:44 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_main_struct(t_main *main)
{
	if (main->parser != NULL)
		free (main->parser);
	if (main != NULL)
		free (main);
}

void	error_exit(t_main *main)
{
	free_main_struct(main);
	perror("Error\ncub3d");
	exit (errno);
}

int	main(int ac, char **av)
{
	t_main	*main;

	main = init_main_struct();
	parse_arguments(ac, av, main);
	free_main_struct(main);
	return (0);
}
