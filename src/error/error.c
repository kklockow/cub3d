/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kklockow <kklockow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:34:53 by kklockow          #+#    #+#             */
/*   Updated: 2024/09/03 14:21:45 by kklockow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_error_message_1(int error_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (error_code == ERR_UAM_C)
		ft_putstr_fd(ERR_UAM_M, STDERR_FILENO);
	if (error_code == ERR_WAA_C)
		ft_putstr_fd(ERR_WAA_M, STDERR_FILENO);
	if (error_code == ERR_WFF_C)
		ft_putstr_fd(ERR_WFF_M, STDERR_FILENO);
	if (error_code == ERR_UOF_C)
		ft_putstr_fd(ERR_UOF_M, STDERR_FILENO);
	if (error_code == ERR_UCF_C)
		ft_putstr_fd(ERR_UCF_M, STDERR_FILENO);
	if (error_code == ERR_TIE_C)
		ft_putstr_fd(ERR_TIE_M, STDERR_FILENO);
	if (error_code == ERR_TNS_C)
		ft_putstr_fd(ERR_TNS_M, STDERR_FILENO);
	if (error_code == ERR_NMF_C)
		ft_putstr_fd(ERR_NMF_M, STDERR_FILENO);
	if (error_code == ERR_WCF_C)
		ft_putstr_fd(ERR_WCF_M, STDERR_FILENO);
	if (error_code == ERR_ELM_C)
		ft_putstr_fd(ERR_ELM_M, STDERR_FILENO);
	if (error_code == ERR_NCW_C)
		ft_putstr_fd(ERR_NCW_M, STDERR_FILENO);
	if (error_code == ERR_NPF_C)
		ft_putstr_fd(ERR_NPF_M, STDERR_FILENO);
}

void	print_error_message_2(int error_code)
{
	if (error_code == ERR_TCR_C)
		ft_putstr_fd(ERR_TCR_M, STDERR_FILENO);
	if (error_code == ERR_GFM_C)
		ft_putstr_fd(ERR_GFM_M, STDERR_FILENO);
	if (error_code == ERR_CNC_C)
		ft_putstr_fd(ERR_CNC_M, STDERR_FILENO);
	if (error_code == ERR_MTL_C)
		ft_putstr_fd(ERR_MTL_M, STDERR_FILENO);
}

void	error_exit(t_main *main, int error_code)
{
	free_structs(main);
	print_error_message_1(error_code);
	print_error_message_2(error_code);
	exit (error_code);
}
