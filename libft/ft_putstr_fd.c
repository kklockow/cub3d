/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstrauss <mstrauss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:56:44 by mstrauss          #+#    #+#             */
/*   Updated: 2024/10/24 18:40:59 by mstrauss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief 		Outputs the string ’s’ to the given file descriptor.
/// @param s	String to output.
/// @param fd	File descriptor on which to write.
void	ft_putstr_fd(char *s, int_fast32_t fd)
{
	unsigned long	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}
